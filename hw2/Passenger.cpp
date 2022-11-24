/* Passenger.cpp 
 * Implementation for a passenger struct 
 * 
 * Created by: Joel Brandinger
 * Date: October 2021
 */

#include <iostream>
#include <string>
#include "Passenger.h"

/* Purpose: prints passenger ID, departing statiion, and arriving statiom
 * Parameters: Location of output text
 * Returns: void
 */
void Passenger::print(std::ostream &output)
{
    output << "[" << id << ", " << from << "->" << to << "]";
}
