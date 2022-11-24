/* PassengerQueue.cpp
 * Implementation for passengerqueue class 
 *
 * Created by: Joel Brandinger
 * Date: October 2021
 *
 */
 
 #include "PassengerQueue.h"
 
 /*   PassengerQueue()
  *
  *   Purpose: default constructr
  * Paramters: none 
  *   Returns: initializes and empty queue 
  */
 PassengerQueue::PassengerQueue()
 {
     
 }
 
 /* ~PassengerQueue()
  * 
  *   Purpose: deallocates memeory
  * Paramters: none 
  *   Returns: nothing
  */
 PassengerQueue::~PassengerQueue()
 {
     
 }
 
 /* front()
  * 
  *   Purpose: returns passenger in the front of the list 
  * Paramters: nothing 
  *   Returns: passenger at the front of the queue 
  */
  Passenger PassengerQueue::front()
  {
      return list.front();
  }
  
  /* enqueue()
   *
   *   Purpose: puts passenger in the queue
   * Paramters: passenger 
   *   Returns: void 
   */
  void PassengerQueue::enqueue(const Passenger &passenger)
  {
      list.push_back(passenger);
  }
  
  /* size()
   * 
   *   Purpose: returns the number of passengers in the queue 
   * Paramters: none 
   *   Returns: number of passengers in the queue 
   */
  int PassengerQueue::size()
  {
      return list.size();
  }
 
  /* dequeue()
   * 
   *   Purpose: remove the passenger from the front of the queue  
   * Paramters: none 
   *   Returns: nothing 
   */
 void PassengerQueue::dequeue()
 {
     list.erase(list.begin());
 }
 
 /* print(ostream &ouptut)
  * 
  *   Purpose: prints all the passengers in the queue 
  * Paramters: output stream 
  *   Returns: void 
  */
 void PassengerQueue::print(std::ostream &output)
 {
     for (int i = 0; i < list.size(); i++) {
         list[i].print(output);
     }
 }
 
 