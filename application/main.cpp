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
#include "HR20.h"

static const int spiClk = 10000000; // 10 MHz


RF12 *rf;
hSPI *hspi;



void setup() {
    Serial.begin(115200);
    hspi = new hSPI(spiClk);
    Serial.println("Calling Constructor ...");
    rf = new RF12();
    Serial.println("Constructor called");

    rf->RFM_init();
    Serial.println("Init called");
    HR20 hr20;
   // hr20.getBatt();
    hr20.getClock();
    hr20.getActualTemperature();

//    getActualTemperature();
//    decodeResponse("?TEMP"); //ERROR
//    decodeResponse("@VER-2.05.99"); //Valid?
//    decodeResponse("$BATT-3.1,OK"); //Valid?

}

uint8_t TxData[] = "UUUU";

// the loop function runs over and over again until power down or reset
void loop() {
    TxData[0] = 0xaa;
    TxData[1] = 0xaa;
    TxData[2] = 0xaa;
    TxData[3] = 0xaa;
    rf->RFM12_TXData(TxData, 4);
    delay(50);
}

