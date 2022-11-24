/* Passenger.h
 * Passenger struct interface
 *
 * Created by: Joel Brandinger
 * Date: October 2021
 *
 */


#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>

struct Passenger
{

        int id, from, to;
        
        Passenger()
        {
                id   = -1;
                from = -1;
                to   = -1;
        }

        Passenger(int newId, int arrivalStation, int departureStation)
        {
                id   = newId;
                from = arrivalStation;
                to   = departureStation;
        }

        // TODO: implement the print function in Passenger.cpp
        void print(std::ostream &output);

};

#endif
