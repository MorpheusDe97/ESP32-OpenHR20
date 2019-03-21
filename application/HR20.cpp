/*
 * HR20.cpp
 *
 *  Created on: 05.03.2019
 *  Author: labor
 *
 *  This module implements the OpenHR20-basis-protocol.
 *  Most important points from the basis-protocol-documentation:
 *
 *  Frameset of a Commando:
 *   ____________________________________________________________
 *  |start sign|    Command    |   -   | optiomal params | CR+LF |
 *   ────────────────────────────────────────────────────────────
 *
 *  Possible start signs:
 *  @   - for an unsolicited value-report after change of a value
 *  !   - for a command to the HR20-thermostat
 *  ?   - value-query
 *  $   - response after value-query
 *
 *
 *
 *  Important note:
 *  Responses are sent after every request, every command and after every query.
 *  If too many requests are sent, the error "Input Buffer Overflow" will
 *  appear.
 *
 *
 */


/**
 *
 */
void encodeQuery()
{


}

/**
 *
 */
void decodeResponse()
{


}

/**
 *
 */
void setDesiredTemperature()
{


}

/**
 *
 */
void getActualTemperature()
{


}

