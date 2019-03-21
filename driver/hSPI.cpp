/*
 * hSPI.cpp
 *
 *  Created on: 11.03.2019
 *      Author: labor
 */

#include "hSPI.h"

hSPI::hSPI(uint32_t clock)
{
    this->clock = clock;
    this->hspi = new SPIClass(HSPI);
    this->hspi->begin();
    pinMode(HSPI_SS, OUTPUT); //HSPI SS
    Serial.println("Constructor hSPI called");
}


uint16_t  hSPI::transmit16(uint16_t data)
{
    uint16_t retVal = 0;
    hspi->beginTransaction(SPISettings(this->clock, MSBFIRST, SPI_MODE0));
    digitalWrite(HSPI_SS, LOW);
    retVal = hspi->transfer16(data);
    digitalWrite(HSPI_SS, HIGH);
    hspi->endTransaction();

    return retVal;
}

