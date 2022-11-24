/* PassengerQueue.h
 * Interface for passengerqueue class 
 *
 * Created by: Joel Brandinger
 * Date: October 2021
 *
 */
 
 #include "Passenger.h"
 #include <vector>
 
 
 #ifndef PASSENGER_QUEUE_H
 #define PASSENGER_QUEUE_H
 
 class PassengerQueue
 {
    public:
        //constructor
        PassengerQueue();
        //destructor 
        ~PassengerQueue();
        //returns passenger at front 
        Passenger front();
        // removes passenger from front of queue
        void      dequeue();
        // adds passenger to the end of queue
        void      enqueue(const Passenger &passenger);
        //returns number of passengers in the queue 
        int       size();
        // prints each passenger in the queue
        void      print(std::ostream &output);
        
    private:
        std::vector <Passenger> list;
        
        
        
 };
 
 #endif