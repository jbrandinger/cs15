/* DatumStack.h
 *
 * Purpose: interface for the DatumStack
 *
 * Created By: Joel Brandinger
 * Date: October 2021 
 */
 
#include "Datum.h"
#include <vector>

#ifndef DATUM_STACK_H
#define DATUM_STACK_H
 
class DatumStack 
{
public:
        DatumStack();
        DatumStack(Datum *arr, int size);
        ~DatumStack();
        // check if stack is empty 
        bool isEmpty();
        // turn current stack into an empty stack 
        void clear();
        // return number of elements in the stack 
        int size();
        // return the top element of the stack 
        Datum top();
        // remove the top element of the stack 
        void pop();
        // add a new element to the stack 
        void push(Datum element);
        // print element at the top of the stack function 
        void print();
             
private:
        std::vector <Datum> stack;
          
};
 
#endif 