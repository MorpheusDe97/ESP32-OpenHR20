

///* The ESP32 has four SPi buses, however as of right now only two of
// * them are available to use, HSPI and VSPI. Simply using the SPI API
// * as illustrated in Arduino examples will use VSPI, leaving HSPI unused.
// *
// * However if we simply intialise two instance of the SPI class for both
// * of these buses both can be used. However when just using these the Arduino
// * way only will actually be outputting at a time.
// *
// * Logic analyser capture is in the same folder as this example as
// * "multiple_bus_output.png"
// *
// * created 30/04/2018 by Alistair Symonds
// */
//#include <SPI.h>
//#include "Arduino.h"
//static const int spiClk = 1000000; // 1 MHz
//
////uninitalised pointers to SPI objects
//SPIClass * vspi = NULL;
//SPIClass * hspi = NULL;
//
//void setup() {
//    Serial.begin(115200);
//    Serial.println("Test");
//  //initialise two instances of the SPIClass attached to VSPI and HSPI respectively
//  vspi = new SPIClass(VSPI);
//  hspi = new SPIClass(HSPI);
//
//  //clock miso mosi ss
//
//  //initialise vspi with default pins
//  //SCLK = 18, MISO = 19, MOSI = 23, SS = 5
//  vspi->begin();
//  //alternatively route through GPIO pins of your choice
//  //hspi->begin(0, 2, 4, 33); //SCLK, MISO, MOSI, SS
//
//  //initialise hspi with default pins
//  //SCLK = 14, MISO = 12, MOSI = 13, SS = 15
//  hspi->begin();
//  //alternatively route through GPIO pins
//  //hspi->begin(25, 26, 27, 32); //SCLK, MISO, MOSI, SS
//
//  //set up slave select pins as outputs as the Arduino API
//  //doesn't handle automatically pulling SS low
//  pinMode(5, OUTPUT); //VSPI SS
//  pinMode(15, OUTPUT); //HSPI SS
//
//
//}
//
//
//
//void vspiCommand() {
//  byte data = 0b01010101; // junk data to illustrate usage
//
//  //use it as you would the regular arduino SPI API
//  vspi->beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
//  digitalWrite(5, LOW); //pull SS slow to prep other end for transfer
//  vspi->transfer(data);
//  digitalWrite(5, HIGH); //pull ss high to signify end of data transfer
//  vspi->endTransaction();
//
//
//}
//
//void hspiCommand() {
//  byte stuff = 0b11001100;
//
//  hspi->beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
//  digitalWrite(15, LOW);
//  hspi->transfer(stuff);
//  digitalWrite(15, HIGH);
//  hspi->endTransaction();
//}
//// the loop function runs over and over again until power down or reset
//void loop() {
//
//    hspiCommand();
//   delay(500);
//}





/* The ESP32 has four SPi buses, however as of right now only two of
 * them are available to use, HSPI and VSPI. Simply using the SPI API
 * as illustrated in Arduino examples will use VSPI, leaving HSPI unused.
 *
 * However if we simply intialise two instance of the SPI class for both
 * of these buses both can be used. However when just using these the Arduino
 * way only will actually be outputting at a time.
 *
 * Logic analyser capture is in the same folder as rf example as
 * "multiple_bus_output.png"
 *
 * created 30/04/2018 by Alistair Symonds
 */
#include <SPI.h>
#include "Arduino.h"
#include "../driver/hSPI.h"
#include "../driver/RF12.h"

static const int spiClk = 10000000; // 10 MHz


RF12 *rf;
hSPI *hspi;

void initRF(void)
{
    rf->spi->transmit16(0x0000);  // Status read
     rf->spi->transmit16(0xC080);  // CLK-frequency / battery-level
     rf->spi->transmit16(0x80D7);  // FIFO ein, 433MHZ-Band, C = 12pF
     rf->spi->transmit16(0xC2AB); // Clock Recovery Auto, Filter digital, DQD-Thresold 3

     rf->spi->transmit16(0xCA81); // FIFO-Level 8 Bit, Sync Pattern ein, High senity Reset aus

     rf->spi->transmit16(0xE000);  // WakeUp aus

     rf->spi->transmit16(0xC800);  // Low Duty Cycle aus

     rf->spi->transmit16(0xC4F3); // AFC immer, +7,5 / -10kHz, Add Freq-Offset zur PLL, Berechne Freq. Offset aus AFC                      // Status read

     rf->spi->transmit16(0xA620);  // Frequenz 433,92MHz  // Status read

     rf->spi->transmit16(0x948C); // VDI Output, VDI Fast, Bandbreite 200kHz, LBA-Gain -6dB, RSSI-Thresold -79dB

     rf->spi->transmit16(0xC610);  // Baudrate 19200

     rf->spi->transmit16(0x8281);  // Empfänger ein, Clock Out aus

    // attachInterrupt(RFM12_IRQ, RFM12_ISR, FALLING);

     rf->spi->transmit16(0x8281);  // Empfänger ein, Clock Out aus

     rf->spi->transmit16(0xCA81);  // set FIFO mode

     rf->spi->transmit16(0xCA83);  // enable FIFO

}

void setup() {
    Serial.begin(115200);
    hspi = new hSPI(spiClk);
    Serial.println("Calling Constructor ...");
    rf = new RF12();
    Serial.println("Constructor called");

    // delay(1000);

    rf->RFM12_init();
    delay(500);
    rf->RFM12_init();
    delay(1000);
    rf->RFM12_init();
    Serial.println("Init called");

    rf->RFM12_setFreq(RF12FREQ(868.92));
    rf->RFM12_setBandWidth(4, 1, 4);// 200kHz Bandbreite, -6dB Verstärkung, DRSSI threshold: -79dBm
    rf->RFM12_setBaud(19200); // 19200 baud
    rf->RFM12_setPower(0, 6); // 1mW Ausgangangsleistung, 120kHz Frequenzshift



}

unsigned char test[] = "123456789";
// the loop function runs over and over again until power down or reset
void loop() {
//    hspi->transmit16(0x1234);  // Empfänger ein, Clock Out aus
//    delay(200);

    rf->RFM12_TXData(test, 9);
    delay(200);
}

