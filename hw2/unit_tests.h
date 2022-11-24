/* unit_tests.h
 *
 * CS 15 Homework 2
 * By: Joel Brandinger
 * Date: October 2021
 * 
 * Tests passenger and passengerqueue
 *
 */

#include <cassert>
#include "PassengerQueue.h"

// create a passenger queue for testing 
PassengerQueue create_queue()
{
    Passenger passenger1(1, 1, 3);
    Passenger passenger2(2, 1, 5);
    Passenger passenger3(3, 2, 6);
    
    PassengerQueue queue;
    
    queue.enqueue(passenger1);
    queue.enqueue(passenger2);
    queue.enqueue(passenger3);
    
    return queue;
}

// creates a passenger 
void create_passenger()
{
    Passenger passenger(1, 1, 3);
}

// prints passenger 
void print_passenger()
{
    Passenger passenger1(1, 1, 3);
    passenger1.print(std::cout);
    
}

// adds a passenger to the queue 
void enqueue()
{
    Passenger passenger1(1, 1, 3);
    Passenger passenger2(2, 1, 5);
    
    PassengerQueue queue;
    
    queue.enqueue(passenger1);
    queue.enqueue(passenger2);
    
    assert(queue.size() == 2);
}

// check to make sure front returns the front passenger in the queue 
void front()
{
    Passenger passenger1(1, 1, 3);
    Passenger passenger2(2, 1, 5);
    
    PassengerQueue queue;
    
    queue.enqueue(passenger1);
    queue.enqueue(passenger2);
    
    assert(queue.front().id == passenger1.id);
    assert(queue.front().from == passenger1.from);
    assert(queue.front().to == passenger1.to);
}

// make sure queue properly records the right size 
void size()
{
    PassengerQueue queue = create_queue();
    
    assert (queue.size() == 3);
}

// removes passenger from the front of the queue 
void dequeue()
{
    PassengerQueue queue = create_queue();
    
    int size = queue.size();
    
    for (int i = 0; i < size; i++) {
        queue.dequeue();
    }
    
    assert (queue.size() == 0);
}

// print all the passengers in the queue 
void print_queue()
{
    PassengerQueue queue = create_queue();
    
    queue.print(std::cout);
}
