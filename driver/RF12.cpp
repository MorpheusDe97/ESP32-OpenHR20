#include "RF12.h"

#define  PAKET_LEN       24
#define  SENSOR_ANZ       6

volatile uint8_t sensor[SENSOR_ANZ][PAKET_LEN];


typedef union SpiState
{
    struct
    {
        unsigned OFFS3 :4;
        unsigned OFFS6 :1;
        unsigned AFCToggle :1;
        unsigned ClockRecoveryLocked :1;
        unsigned DataQuality :1;
        unsigned Rssi :1;
        unsigned FifoEmpty :1;
        unsigned LowBatt :1;
        unsigned ExternalInterrupt :1;
        unsigned WakeUp :1;
        unsigned RegisterUnderrun :1;
        unsigned PowerOnReset :1;
        unsigned RegisterInput :1;
    };
    uint16_t spiState;
} SpiState_u;

RF12::RF12()
{
    this->spi = new hSPI(this->spiClk);
    Serial.println("Constructor RF12 called");
}

RF12::RF12(uint32_t spiClk)
{
    this->spiClk = spiClk;
    this->spi = new hSPI(this->spiClk);
}

//TODO: nIRQ anschließen
void RF12::RFM12_ISR(void)
{
    static uint8_t data[32];
    static uint8_t checksum = 0;
    static uint8_t bytecount = 0;
    uint8_t i, sensor_nr, byte;

    digitalWrite(RFM12_SCK, LOW);         // CLK auf L
    Serial.println("CLKL");
    digitalWrite(RFM12_SDI, LOW);         // DATA auf L
    digitalWrite(RFM12_CS, LOW);          // CS auf L

    byte = 0xB0;                                  // Receive FIFO

    for (i = 0; i < 8; i++)                       // Kommando senden
    {
        if (byte & 0x80)
        {
            digitalWrite(RFM12_SDI, HIGH);        // DATA auf H
        }
        else
        {
            digitalWrite(RFM12_SDI, LOW);         // DATA auf L
        }
        digitalWrite(RFM12_SCK, HIGH);            // Clock auf H
        Serial.println("CLKH");
        byte = (byte << 1);                       // nächstes Bit nach oben
        digitalWrite(RFM12_SCK, LOW);             // Clock auf L
        Serial.println("CLKL");
    }

    byte = 0;

    for (char j = 0; j < 8; j++)
    {
        byte = (byte << 1);                 // eins höher schieben
        if (digitalRead(RFM12_SDO) == 1)    // Bit 1?
        {
            byte = (byte | 0x01);         // ja
        }
        digitalWrite(RFM12_SCK, HIGH);  // CLK auf H
        Serial.println("CLKH");
        digitalWrite(RFM12_SCK, LOW);   // CLK auf L
        Serial.println("CLKL");
    }
    digitalWrite(RFM12_CS, HIGH);     // CS auf H

    data[bytecount] = byte;                      // Daten speichern
    bytecount++;
    checksum ^= byte;                             // XOR-Prüfsumme

    if (bytecount == PAKET_LEN)                   // fertig?
    {
        RF12::RFM12_send_cmd(0xCA81);               // set FIFO mode
        RF12::RFM12_send_cmd(0xCA83);               // enable FIFO

        if (checksum == 0)                        // Checksumme ok?
        {
            sensor_nr = (data[0] & 0x0F) - 1;    // jetzt ab 0
            if (sensor_nr < SENSOR_ANZ)           // im gültigen Beeich?
            {
                data[bytecount - 1] = 1; // 1 ins letzte Byte (Checksumme) für neue Daten
                memcpy((void *) sensor[sensor_nr], (void const *) data,
                PAKET_LEN);
            }
        }
        checksum = 0;
        bytecount = 0;
    }
}

void RF12::RFM12_init(void)
{
    Serial.println("Initialising RFM12");

    delay(200);

    this->spi->transmit16(0xC0E0);
#ifdef FREQ433
    this->spi->transmit16(0x80D7);         // Enable FIFO
#elif defined FREQ868
    this->spi->transmit16(0x80E7);         //868MHz, EL (Enable TX Register), EF(Enable FIFI Buffer), 11.5pF
#endif
    this->spi->transmit16(0xC2AB);         // Data Filter: internal
    this->spi->transmit16(0xCA81);         // Set FIFO mode
    this->spi->transmit16(0xE000);         // disable wakeuptimer
    this->spi->transmit16(0xC800);         // disable low duty cycle
    this->spi->transmit16(0xC4F7); // AFC settings: autotuning: -10kHz...+7,5kHz
    this->decodeSPIState(this->spi->transmit16(0x0000));       // receive status

}

void RF12::RFM12_setFreq(unsigned short freq)
{
    if (freq < 96)                // 430,2400MHz
        freq = 96;
    else if (freq > 3903)         // 439,7575MHz
        freq = 3903;
    this->spi->transmit16(0xA000 | freq);
}

void RF12::RFM12_setBaud(unsigned short baud)
{
    if (baud < 663)
        return;
    if (baud < 5400)                  // Baudrate= 344827,58621/(R+1)/(1+CS*7)
        this->spi->transmit16(0xC680 | ((43104 / baud) - 1));
    else
        this->spi->transmit16(0xC600 | ((344828UL / baud) - 1));
}

void RF12::RFM12_setPower(uint8_t power, uint8_t mod)
{
    this->spi->transmit16(0x9800 | (power & 7) | ((mod & 15) << 4));
}

void RF12::RFM12_setBandWidth(unsigned char bandwidth, unsigned char gain,
        unsigned char drssi)
{
    this->spi->transmit16(
            0x9400 | ((bandwidth & 7) << 5) | ((gain & 3) << 3) | (drssi & 7));
}

void RF12::RFM12_Ready(unsigned short sending)
{
    if (sending)
    {
        uint16_t timeout = 1000;
        digitalWrite(RFM12_SDI, LOW);
        digitalWrite(RFM12_CS, LOW);
        while (!digitalRead(RFM12_SDO) && timeout)
        {
            timeout--;
            delayMicroseconds(10);
        }
    }
}

void RF12::decodeSPIState(uint16_t state)
{
    Serial.println(state, BIN);
    SpiState_u spistate;
    spistate.spiState = state;

    if (spistate.RegisterInput)
    {
        Serial.println(
                "Register-Input: Senderegister ist bereit fuer neue Sendedaten");
    }
    if (spistate.PowerOnReset)
    {
        Serial.println(
                "Power On Reset: Alle Register wurden mit Vorgabewerten geladen / überschrieben");
    }
    if (spistate.RegisterUnderrun)
    {
        Serial.println(
                "Die Empfangs-FIFO ist übergelaufen, weil Daten nicht zügig genug abgeholt wurden. Die FIFO ist blockiert bis zum nächsten Synchronwort");
    }
    if (spistate.WakeUp)
    {
        Serial.println("Der Aufweck-Timer ist abgelaufen");
    }
    if (spistate.ExternalInterrupt)
    {
        Serial.println("Es liegt Low-Pegel am Eingang INT11 vor");
    }
    if (spistate.LowBatt)
    {
        Serial.println("Es liegt Unterspannung vor");
    }
    if (spistate.FifoEmpty)
    {
        Serial.println("Der FIFO-Puffer ist leer");
    }
    if (spistate.Rssi)
    {
        Serial.println("Die Signalstärke ist über dem eingestellten Limit");
    }
    if (spistate.DataQuality)
    {
        Serial.println("Der Ausgang des Datenqualitätsbewerters");
    }
    if (spistate.ClockRecoveryLocked)
    {
        Serial.println("Die Taktwiederherstellung ist eingerastet");
    }
    if (spistate.AFCToggle)
    {
        Serial.println(
                "Kippt mit jedem AFC-Zyklus, d.h. nachfolgende Bits ändern sich (gemessen wurden etwa 4 kHz, s.u.)");
    }
    if (spistate.OFFS6)
    {
        Serial.println("MSB = Vorzeichen des AFC-Offsets");
    }
    if (spistate.OFFS3)
    {
        Serial.println(
                "Letzte 4 Bits vom AFC-Offset. Bei entsprechend begrenzter AFC (Vorgabe) entspricht dies dem tatsächlichen AFC-Offset. Ansonsten muss man den AFC-Abstimmvorgang durch zyklisches Auslesen des Statusregisters beobachten und die fehlenden Bits extrapolieren");
    }
}

void RF12::RFM12_TXData(unsigned char *buffer, uint8_t size)
{
    this->spi->transmit16(0x8208);
    unsigned char i;
    this->spi->transmit16(0x8208);         // turn on crystal
    this->spi->transmit16(0x0000);         // receive status
    this->spi->transmit16(0x0000);         // receive status

    this->spi->transmit16(0x8238);         // TX on

    RFM12_Ready(1);

    this->spi->transmit16(0xB8AA); //preamble
    RFM12_Ready(1);
    this->spi->transmit16(0xB8AA); //preamble
    RFM12_Ready(1);

    //Synchron Pattern 2DD4h according to Programming Guide Point 8: FIFO and Reset Mode Command
    this->spi->transmit16(0xB82D); //synchronization
    RFM12_Ready(1);
    this->spi->transmit16(0xB8D4); //synchronization
    RFM12_Ready(1);

    for (i = 0; i < size; i++)
    {
        RFM12_Ready(1);

//        #ifdef HAMMING_CODE
//            rf12_trans(0xB800|(pgm_read_byte(&hamminge[*data/16])));    //high-byte(*data++));
//            rf12_ready(1);
//            rf12_trans(0xB800|(pgm_read_byte(&hamminge[*data&15])));    //low-byte
//            data++;
//        #else
        this->spi->transmit16(0xB800 | (*buffer++));
        //#endif
    }
    RFM12_Ready(1);
    delay(10);
    this->spi->transmit16(0x8208);         // TX off
    this->spi->transmit16(0x8201);         // enter sleep
}

void RF12::RFM12_send_cmd(unsigned int command)
{
    unsigned char i;
    digitalWrite(RFM12_CS, LOW);           // CS auf L
    digitalWrite(RFM12_SCK, LOW);    // CLK auf H
    for (i = 0; i < 16; i++)
    {
        if (command & 0x8000)
        {
            digitalWrite(RFM12_SDI, HIGH);  // DATA auf H
        }
        else
        {
            digitalWrite(RFM12_SDI, LOW);   // DATA auf L
        }
        digitalWrite(RFM12_SCK, HIGH);    // CLK auf H
        digitalWrite(RFM12_SCK, HIGH);     // CLK auf H
        command = (command << 1);           // nächstes Bit nach oben
    }
    digitalWrite(RFM12_CS, LOW);           // CS auf L
}

uint16_t RF12::RFM12_read_status(void)
{
    uint16_t statusword = 0;
    unsigned char i = 0;

    digitalWrite(RFM12_SCK, LOW);       // CLK auf L
    digitalWrite(RFM12_SDI, LOW);       // DATA auf L

    digitalWrite(RFM12_CS, LOW);        // CS auf L

    for (i = 0; i < 16; i++)
    {
        statusword = (statusword << 1);           // eins höher schieben
        if (digitalRead(RFM12_SDO) == 1) // Bit 1?
        {
            statusword = (statusword | 0x0001);   // ja
        }
        digitalWrite(RFM12_SCK, HIGH);  // CLK auf H
        digitalWrite(RFM12_SCK, LOW);   // CLK auf L
    }
    digitalWrite(RFM12_CS, HIGH);         // CS auf H

    return statusword;
}
