/* MetroSim.cpp 
 * Implementation for MetroSim 
 *
 * Created by: Joel Brandinger
 * Date: October 2021 
 */

#include "MetroSim.h"
#include <sstream>

MetroSim::MetroSim()
{
    currentStation = 1;
    nextID = 1;
}

MetroSim::~MetroSim()
{
    
}

/* start ()
 *   Purpose: initializes the MetroSim program and starts running the
              command loop
 * Paramters: stations file, output file, and command file if there is one 
 *   Returns: void 
 */
void MetroSim::start(std::fstream &input, std::fstream &output, 
                     std::istream &commands)
{
    std::string line;
    int counter = 1;
    getline(input, line);
    
    while (not input.eof()) {
        stations.push_back(newStation(line, counter));
        counter++;
        getline(input, line);
    }
    
    for (unsigned long int i = 0; i < stations.size(); i++) {
        train.push_back(createEmptyqueue());
    }
    
    command_loop(output, commands);
}

/* createEmptyqueue()
 *   Purpose: creates an empty queue to for each stop on the train 
 * Paramters: none 
 *   Returns: empty Passenger queue 
 */
PassengerQueue MetroSim::createEmptyqueue()
{
    PassengerQueue queue;
    return queue;
}

/* newStation()
 *   Purpose: creates a new station from the input file 
 * Paramters: name of the station and station number 
 *   Returns: a new station 
 */
Station MetroSim::newStation(std::string name, int number)
{
    Station new_station;
    new_station.station_name = name;
    new_station.station_number = number;
    
    return new_station;
}

/* addPassenger()
 *   Purpose: adds a new passenger to the simulation 
 * Paramters: arrival and departing stations 
 *   Returns: none 
 */
void MetroSim::addPassenger(int arrival, int departure)
{
    Passenger p = Passenger(nextID, arrival, departure);
    stations[arrival - 1].queue.enqueue(p);
    
    nextID++;
}

/* command_loop()
 *   Purpose: performs commands given until end of file or user decides to end
              simulation
 * Paramters: none 
 *   Returns: none 
 */
void MetroSim::command_loop(std::fstream &output, std::istream &commands)
{
    std::string cmd;
    int value;
    printState();
    
    while (cmd != "m f") {
        std::cout << "Command? ";
        commands >> cmd;
        if (cmd == "p") {
            commands >> value;
            int num1 = value;
            commands >> value;
            int num2 = value;
            addPassenger(num1, num2);
            printState();
        } else if (cmd == "m") {
            commands >> cmd;
            if (cmd == "f") {
                cmd = "m f";
            } else {
                moveTrain(output);
                printState();
            }
        } 
    }
    std::cout << "Thanks for playing MetroSim. Have a nice day!" << std::endl;
}

/* printState()
 *   Purpose: prints current location of the train, all passengers on the
 *            train, and all passengers at each station 
 * Paramters: none 
 *   Returns: none 
 */
void MetroSim::printState()
{
    std::cout << "Passengers on the train: {";
    for (unsigned long int i = 0; i < train.size(); i++) {
        train[i].print(std::cout);
    }
    std::cout << "}" << std::endl;
    
    for (int i = 0; i < stations.size(); i++) {
        if (i == (currentStation - 1)) {
            std::cout << "TRAIN: " << "[" << stations[i].station_number 
                      << "] " << stations[i].station_name << " {";
                      stations[i].queue.print(std::cout);
                      std::cout << "}" << std::endl;
        } else {
            std::cout << "       [" << stations[i].station_number << "] "
                      << stations[i].station_name << " {";
                      stations[i].queue.print(std::cout);
                      std::cout << "}" << std::endl;
        }
    }
}

/* moveTrain(fstream &output)
 *   Purpose: moves the train to the next station. Boards all passengers at
 *            that station and departs all passengers that wish to get off 
 *            at that staion 
 * Paramters: output file 
 *   Returns: none 
 */
void MetroSim::moveTrain(std::fstream &output)
{    
    pick_up_passengers();
    
    if (currentStation == stations.size()) {
        currentStation = 1;
    } else {
        currentStation++;
    }
    exit_passengers(output);
    
}

/* pick_up_passengers()
 *   Purpose: picks up passengers at the station and puts them on the train 
 * Paramters: none 
 *   Returns: none 
 */
void MetroSim::pick_up_passengers()
{
    int temp;
    int lineSize = stations[currentStation - 1].queue.size();
    
    for (int i = 0; i < lineSize; i++) {
        temp = stations[currentStation - 1].queue.front().to;
        train[temp - 1].enqueue(stations[currentStation - 1].queue.front());
        stations[currentStation - 1].queue.dequeue();
    }
}

/* exit_passengers()
 *   Purpose: takes passengers off the train and prints to output file 
 * Paramters: output address
 *   Returns: none 
 */
void MetroSim::exit_passengers(std::fstream &output)
{    
    int queueSize = train[currentStation - 1].size();
    
    for (int i = 0; i < queueSize; i++) {
        output << "Passenger " << train[currentStation - 1].front().id
               << " left the train at station "
               << stations[currentStation - 1].station_name << std::endl;
        train[currentStation - 1].dequeue();
    }
}