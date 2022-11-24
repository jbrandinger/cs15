/* unit_tets.h
 *
 * Purpose: test all functions of the DatumStack class
 *
 * Created By: Joel Brandinger
 * Date: October 2021
 */
 
#include "DatumStack.h"
#include "RPNCalc.h"
#include "parser.cpp"
#include <cassert>

// create a DatumStack that can be used for testing 
DatumStack create_stack()
{
    int x = 5;
    bool y = true;
    std::string z = "{ 10 5 +}";
    
    Datum a(x);
    Datum b(y);
    Datum c(z);
    
    Datum copy[3] = {a, b, c};
    Datum *arr = copy;
    
    DatumStack stack(arr, 3);
    
    return stack;
}

// test default constructor to make sure there are no memory leaks 
// or run time errors 
void DatumStack_constructor()
{
    DatumStack stack;
}

// test constructor that passes in an array of Datums and int size 
void DatumStack_constructor2()
{
    DatumStack stack = create_stack();
}

// test print function 
void print_stack()
{
    DatumStack stack = create_stack();
    stack.print();
}

// test isEmpty 
void stack_isEmpty()
{
    DatumStack stack1;
    assert(stack1.isEmpty() == true);
    
    DatumStack stack2 = create_stack();
    assert(stack2.isEmpty() == false);
}

// test clear
void clear_stack()
{
    DatumStack stack = create_stack();
    assert(stack.isEmpty() == false);
    std::cout << "stack before clear" << std::endl;
    stack.print();
    
    stack.clear();
    assert(stack.isEmpty() == true);
    std::cout << "stack after clear" << std::endl;
    stack.print();
}

// test size function 
void test_size()
{
    DatumStack stack = create_stack();
    std::cout << "stack has " << stack.size() << " elements" << std::endl;
    assert(stack.size() == 3);
}

// test to return top of stack
void return_top()
{
    //DatumStack stack1;   ** successfully fails **
    //std::cout << "Top of stack: " << stack1.top().toString() << std::endl;
    
    DatumStack stack2 = create_stack();
    std::cout << "Top of stack: " << stack2.top().toString() << std::endl;
}

// test removing element at the top of the stack 
void test_pop()
{
    // DatumStack stack1; 
    // stack1.pop();   ** successfully fails **
    // std::cout << "Popped stack: " << std::endl;
    // stack1.print();
    
    DatumStack stack2 = create_stack();
    std::cout << "stack before pop: " << std::endl;
    stack2.print();
    
    stack2.pop();
    std::cout << "stack after pop: " << std::endl;
    stack2.print();
}

// test adding a new element to the stack
void add_to_stack()
{
    DatumStack stack = create_stack();
    int x = 8;
    Datum d(x);
    
    assert(stack.size() == 3);
    stack.push(d);
    stack.print();
    assert(stack.size() == 4);
}

//test RPNCalc default constructor 
void create_RPNCalc()
{
    RPNCalc calc;
}