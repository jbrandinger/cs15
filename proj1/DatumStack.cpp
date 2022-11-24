/* DatumStack.cpp 
 *
 * Purpose: Implemenetation of the DatumStack class
 *
 * Created By: Joel Brandinger
 * Date: October 2021
 */
 
#include "DatumStack.h"
#include <iostream>

/* DatumStack()
 * Purpose: inializes an empty DatumStack 
 */
DatumStack::DatumStack()
{
    
}

/* DatumStack(Datum *arr, int size)
 *    Purpose: initializes a DatumStack from an arrray of Datums and int 
 *             of the size of the array 
 * Parameters: array of Datums and an int of the size 
 */
DatumStack::DatumStack(Datum *arr, int size)
{
     for (int i = 0; i < size; i++) {
         stack.push_back(arr[i]);
     }
}
 
/* ~DatumStack()
 * Purpose: destructor
 */
DatumStack::~DatumStack()
{
         
}

/* printStack()
 * Purpose: print stack 
 */
void DatumStack::print()
{
    if (stack.size() == 0) {
        throw std::runtime_error("empty_stack");
    }
    
    std::cout << stack.back().toString() << std::endl;
}

/* isEmpty()
 * Purpose: check if stack is empty 
 * Returns: true if empty, false if not 
 */
bool DatumStack::isEmpty()
{
    return stack.size() == 0;
}

/* clear()
 * Purpose: clear the stack 
 */
void DatumStack::clear()
{
    stack.clear();
}

/* size()
 * Purpose: return the number of elements in the stack 
 * Returns: size of the stack 
 */
int DatumStack::size()
{
    return stack.size();
}

/* top()
 * Purpose: return the element at the top of the stack 
 * Returns: Datum at the top of the stack 
 */
Datum DatumStack::top()
{
    if (stack.size() == 0) {
        throw std::runtime_error("empty_stack");
    }
        
    return stack.back();
}

/* pop()
 * Purpose: remove the element at the top of the stack 
 */
void DatumStack::pop()
{
    if (stack.size() == 0) {
        throw std::runtime_error("empty_stack");
    }
    
    stack.pop_back();
}
/* push()
 * Purpose: add new element to the stack 
 * Parameters: Datum to be added to the stack 
 */
void DatumStack::push(Datum element)
{
    stack.push_back(element);
}

