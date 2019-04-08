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

class HR20{
public:

    void getPosition(void);
    void getClock(void);
    void getVersion(void);
    void getActualTemperature(void);
    void getBatt(void);
    void setDesiredTemperature(int temperature);

private:

};




#endif /* HR20_H_ */
