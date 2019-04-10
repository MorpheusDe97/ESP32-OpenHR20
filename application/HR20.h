/*
 * HR20.h
 *
 *  Created on: 05.03.2019
 *      Author: labor
 */

#ifndef HR20_H_
#define HR20_H_
#include <string>


typedef enum startsign
{
    HR20_UNSOLICITED_VALUE_MESSAGE = 1, // @: Unsolicited value message after change of value
    HR20_COMMAND = 2,                   // !: Command to the HR20E
    HR20_QUERY = 3,                     // ?: Value Query to the HR20E
    HR20_RESPONSE = 4,                  // $: Response from HR20E after value query
    HR20_UNDEFINED = 5
}startsign_e;

/**
 * If an invalid sign or an incomplete command is received by the HR20-thermostat,
 * it will respond by an Error-Code.
 *
 * $ERR-<ERRORCODE>=TEXT
 * The codes are divided as follows:
 * 100-199 -> protocol error
 * 200-255 -> system error
 *
 */
typedef enum errorCode
{
    ERROR_OK = 0,                       // Everything works
    ERROR_PARA = 101,                   // Parameter is missing or wrong
    ERROR_UNKNOWN_COMMAND = 103,        // Unknown Command
    ERROR_INBuffer = 104,               // Input Buffer overflow
    ERROR_OUTBUFFER = 105,              // Output Buffer overflow
    ERROR_COMMANDTYPE = 106,            // Startsign is not valid
    ERROR_VALUE = 107,                  // Value for a parameter is not valid
    ERROR_BATTLOW = 201,                // Battery is low / empty
    ERROR_MOTBLOCK = 202                // Motor is blocked
}errorCode_e;


class HR20{
public:

    void getPosition(void);
    void getClock(void);
    void getVersion(void);
    double getActualTemperature(void);
    bool getBattOk(void);
    void setDesiredTemperature(int temperature);

private:

};




#endif /* HR20_H_ */
