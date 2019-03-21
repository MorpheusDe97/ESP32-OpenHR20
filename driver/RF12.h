
#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include "hSPI.h"
#define RFM12_SDI   12
#define RFM12_SCK   14
#define RFM12_SDO   13
#define RFM12_CS    15
#define RFM12_IRQ   4


#define HAMMING_CODE

// which frequency to use
//#define FREQ433
#define FREQ868

// macro for calculating frequency value out of frequency in MHz
#ifdef FREQ433
    #define RF12FREQ(freq)  ((freq-430.0)/0.0025)
#elif defined FREQ868
    #define RF12FREQ(freq)  ((freq-860.0)/0.005)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 *
 *
 * Basecode:
 * https://www.arduinoforum.de/arduino-Thread-ESP8266-RFM12-MCP23S17-Experimente
 *
 * Useful Links:
 * https://www.hoperf.com/modules/rf_transceiver/RFM12BW.html
 *
 *
 *
 *
 */
class RF12
{
public:
    hSPI *spi;
    RF12();
    RF12(uint32_t spiClk);
    static void RFM12_send_cmd(unsigned int command);
    void RFM12_init(void);
    void RFM12_setFreq(unsigned short freq);
    void RFM12_setPower(uint8_t power, uint8_t mod);
    void RFM12_setBandWidth(unsigned char bandwidth, unsigned char gain, unsigned char drssi);
    void RFM12_setBaud(unsigned short baud);
    void RFM12_TXData(unsigned char *buffer, uint8_t size);
    void RFM12_RXData(unsigned char *buffer, uint8_t size);
    void RFM12_Ready(uint16_t sending);
    void RFM12_read_fifo(char *, char len);
    void decodeSPIState(uint16_t state);
    uint16_t RFM12_read_status(void);
    void hspiLoop(void);
private:
    static void RFM12_ISR(void);

     int spiClk = 1000000; // 1 MHz
protected:
};




#ifdef __cplusplus
}
#endif
