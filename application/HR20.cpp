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
 *  Important note:
 *  Responses are sent after every request, every command and after every query.
 *  If too many requests are sent, the error "Input Buffer Overflow" will
 *  appear.
 *
 *  For more information, see https://github.com/OpenHR20/OpenHR20/blob/master/trunk/doc/protkoll/Basis_Protokoll.pdf
 *
 */

#include "HR20.h"
#include "Arduino.h"
#include <vector>
#include <algorithm>
#include <sstream>

std::vector<std::string> commands =
{ "TEMP", "VER", "BATT", "CLOCK", "VALVE", "CAL" };
void decodeResponse(std::string response, startsign_e *startsign,
        std::string *command, std::string *param);

/**
 *
 */
std::string encodeQuery(startsign_e startsign, std::string command,
        std::string param)
{
    std::string query = "";
    switch (startsign)
    {
    case HR20_UNSOLICITED_VALUE_MESSAGE:
        query += "@";
        break;
    case HR20_COMMAND:
        query += "!";
        break;
    case HR20_QUERY:
        query += "?";
        break;
    case HR20_RESPONSE:
        query += "$";
        break;
    default:
        return "";
    }
    if (std::find(commands.begin(), commands.end(), command) != commands.end())
    {
        query += command;
        if (param != "")
        {
            query += "-";
            query += param;
        }
        query += "\r\n";
        //Now the query is ready!
        return query;
    }
    else
    {
        return "";
    }
}

std::string encodeQuery(startsign_e startsign, std::string command)
{
    return encodeQuery(startsign, command, "");
}

std::string handleQuery(std::string query)
{
    startsign_e startsign = HR20_UNDEFINED;
    std::string command = "", param = "", response = "";


    //1. Send Query as request
    Serial.println(query.c_str());

    //2. Wait for Response
    do{
        response = Serial.readString().c_str();
    }while(response == "");

    //3. Decode Response
    decodeResponse(response, &startsign, &command, &param);
    //Response belongs to query??
    if(query.find(command) != std::string::npos && startsign == HR20_RESPONSE && command != "" )
    {
        Serial.println("Success");
    }
    else
    {
        Serial.println("Error");
    }
    return param;
}

errorCode_e decodeError(std::string response, std::string *param)
{
    if(response.find("ERR") != std::string::npos)
    {
        response.erase(0, 1);
        std::string errorCode = "";
        std::istringstream istring(response);
        std::getline(istring, errorCode, '-');
        std::getline(istring, errorCode, '=');

        uint8_t errorCodeInt = ::atoi(errorCode.c_str());

        if(param != NULL)
        {
            std::getline(istring, *param);
        }

        return (errorCode_e)errorCodeInt;

    }
    else
    {
        return ERROR_OK;
    }
}


/**
 *
 */
void decodeResponse(std::string response, startsign_e *startsign,
        std::string *command, std::string *param)
{
    if (startsign != NULL && command != NULL && param != NULL)
    {
        //The Startsign should be either '@' or '$'
        if (response[0] == '@')
        {
            *startsign = HR20_UNSOLICITED_VALUE_MESSAGE;
            Serial.println("Unsolicited Value message");
        }
        else if (response[0] == '$')
        {
            Serial.println("Response");
            *startsign = HR20_RESPONSE;
        }
        else
        {
            Serial.println("Invalid response");
            return;
        }
        errorCode_e errorCode = decodeError(response, param);
        if(errorCode == ERROR_OK)
        {
            response.erase(0, 1);
            Serial.println(response.c_str());
            std::istringstream istring(response);

            //First: extract the command:
            if (std::getline(istring, *command, '-')
                    && std::find(commands.begin(), commands.end(), *command)
                            != commands.end())
            {
                //substring is a valid command
                Serial.println(command->c_str());
                std::getline(istring, *param, '-');
            }
            else
            {
                Serial.println("Invalid response");
                return;
            }
        }
        else
        {
            Serial.println("Error!");
            switch(errorCode)
            {
            case ERROR_PARA:
                Serial.println("Parameter is missing or wrong");
                break;
            case ERROR_UNKNOWN_COMMAND:
                Serial.println("Unknown Command");
                break;
            case ERROR_INBuffer:
                Serial.println("Input Buffer overflow");
                break;
            case ERROR_OUTBUFFER:
                Serial.println("Output Buffer overflow");
                break;
            case ERROR_COMMANDTYPE:
                Serial.println("Startsign is not valid");
                break;
            case ERROR_VALUE:
                Serial.println("Value for a parameter is not valid");
                break;
            case ERROR_BATTLOW:
                Serial.println("Battery is low / empty");
                break;
            case ERROR_MOTBLOCK:
                Serial.println("Motor is blocked");
                break;
            default:break;
            }
            Serial.println(param->c_str());
        }

    }
}


/**
 *
 */
void HR20::setDesiredTemperature(int temperature)
{
    if (temperature % 5)
    {
        return; // -> temperature may only be XX.5°C or XX.0°C
    }
    std::ostringstream ss;
    ss << temperature;
    std::string query;
    std::string command = "TEMP=" + ss.str();
    query = encodeQuery(HR20_COMMAND, command);
    handleQuery(query);
}

/**
 *
 */
double HR20::getActualTemperature()
{
    std::string query, response;
    query = encodeQuery(HR20_QUERY, "TEMP");
    response = handleQuery(query);
    std::istringstream istring(response);
    //First: extract the command:
    std::string temp;
    std::getline(istring, temp, '=');
    std::getline(istring, temp, ',');
    double tempf = ::atof(temp.c_str());
    Serial.println(tempf);
    return tempf;
}

void HR20::getVersion()
{
    std::string query;
    query = encodeQuery(HR20_QUERY, "VER");
    handleQuery(query);
}

void HR20::getClock()
{
    std::string query;
    query = encodeQuery(HR20_QUERY, "CLOCK");
    handleQuery(query);
}

void HR20::getPosition()
{
    std::string query;
    query = encodeQuery(HR20_QUERY, "VALVE");
    handleQuery(query);

}

bool HR20::getBattOk()
{
    std::string query;
    query = encodeQuery(HR20_QUERY, "BATT");
    handleQuery(query);
    return true;
}

