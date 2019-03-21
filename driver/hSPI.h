/*
 * hSPI.h
 *
 *  Created on: 11.03.2019
 *      Author: Marcel Hunfeld
 */

#ifndef DRIVER_HSPI_H_
#define DRIVER_HSPI_H_
#include <SPI.h>
#include "Arduino.h"

#define HSPI_SS 15

class hSPI{
private:
    SPIClass * hspi = NULL;
    uint32_t clock;
public:
    hSPI(uint32_t clock);
    ~hSPI();
    uint16_t transmit16(uint16_t data);
};



#endif /* DRIVER_HSPI_H_ */
