/*
 *
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "PassengerQueue.h"
#include <vector>
#include <fstream>
#include <iostream>
// Put any other structs you need here
struct Station {
    std::string station_name;
    PassengerQueue queue;
    int station_number;
}; 

class MetroSim
{ 
    
public:
    // constructor 
    MetroSim();
    // Destructor
    ~MetroSim();
    //intitializes MetroSim
    void start(std::fstream &input, std::fstream &output,
               std::istream &commands);
    //add passenger
    void addPassenger(int arrival, int departure);
    // moves train to next station 
    void moveTrain(std::fstream &output);
    // prints passenger that left the train to output text 
    void printDepart();
    // ends the MetroSim simulation
    void finish();
    // prints the current station of the train and all passengers aboard
    void printState();

private:
    std::vector <PassengerQueue> train;
    std::vector <Station> stations;
    int currentStation;
    int nextID;
    Station newStation(std::string name, int number);
    //PassengerQueue newQueue();
    void command_loop(std::fstream &output, std::istream &commands);
    PassengerQueue createEmptyqueue();
    void pick_up_passengers();
    void exit_passengers(std::fstream &output);
};

#endif
