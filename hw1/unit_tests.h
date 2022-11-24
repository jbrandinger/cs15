/* 
 * unit_tests.h
 * 
 * CS 15 homework 1
 * by C.R. Calabrese, January 2021
 * 
 * Uses Matt Russell's unit_test framework to test the CharArrayList and
 * CharLinkedList.
 * More information on this testing framework can be found in the Lab 1
 * handout
 */

#include <cassert>
#include "CharArrayList.h"
#include "CharLinkedList.h"

/********************************************************************\
*                       CHAR ARRAY LIST TESTS                        *
\********************************************************************/

// helper functions to initialize one char and multi char lists 
// for unit tests
CharArrayList oneCharlist();
CharArrayList multiCharlist(); 

/* default constructor test
 * Run the ArrayList default constructor to make sure there are no runtime
 * errors or memory leaks
 */
void default_constructor_AL()
{
    CharArrayList testArrayList;
}

/* second constructor test
 * Run the 2nd ArrayList constructor that initialized a char 
 * to make sure there are no runtime
 * errors or memory leaks
 */
void oneChar_constructor_AL()
{
    char c = 'a';
    CharArrayList list(c);

    assert(list.size() == 1);
    assert(not list.isEmpty());
    list.print();
}

/* third constructor test
 * Run the 3rd ArrayList constructor that initializes a char array  
 * to make sure there are no runtime
 * errors or memory leaks
 */
void multiChar_constructor_AL()
{
    char init[] = {'a','b','c','d','e'};
    char *arr = init;

    CharArrayList list(arr, 5);

    assert(list.size() == 5);
    assert(not list.isEmpty());
    list.print();
}

/* isEmpty function test 
 * test to see if an empty intialized list is empty 
 */
void isEmpty_AL()
{
    CharArrayList list1;
    CharArrayList list2 = oneCharlist();
    CharArrayList list3 = multiCharlist();

    assert(list1.isEmpty());
    assert(not list2.isEmpty());
    assert(not list3.isEmpty());
}
/* test to see if size function 
 * returns proper size for empty list,
 * one char list, and multi char list 
 */
void size_AL()
{
    CharArrayList list1;
    CharArrayList list2 = oneCharlist();
    CharArrayList list3 = multiCharlist();

    assert(list1.size() == 0);
    assert(list2.size() == 1);
    assert(list3.size() == 5);

}

/* checks to see if "first" function works and returns the first element
 * of the list 
 */
void first_AL()
{
    //CharArrayList list1;
    CharArrayList list2 = oneCharlist();
    CharArrayList list3 = multiCharlist();

    //assert(list1.first());        correctly fails
    assert(list2.first() == 'a');
    assert(list3.first() == '1');
}

/* checks to see if "last" function works and returns the last element
 * of the list 
 */
void last_AL()
{
    //CharArrayList list1;
    CharArrayList list2 = oneCharlist();
    CharArrayList list3 = multiCharlist();

    //assert(list1.last());        correctly fails
    assert(list2.last() == 'a');
    assert(list3.last() == '5');
}

/* checks "elementAt" function 
 */
void elementAt_AL()
{
    //CharArrayList list1;
    CharArrayList list2 = oneCharlist();
    CharArrayList list3 = multiCharlist();

    //assert(list1.elementAt(0));  correctly fails
    assert(list2.elementAt(0) == 'a');
    assert(list3.elementAt(3) == '4');
    //assert(list3.elementAt(10) == '4'); correctly fails

}

/* tests print function to make sure it properly outputs the list 
 * in the correct order 
 */
void print_AL()
{
    CharArrayList list1;
    CharArrayList list2 = oneCharlist();
    CharArrayList list3 = multiCharlist();

    list1.print();
    list2.print();
    list3.print();
}

/* Tests clear function to make sure a list is cleared an prints out the
 * result to make sure it is an empty list of size 0
 */
void clear_AL()
{
    CharArrayList list1;
    CharArrayList list2 = oneCharlist();
    CharArrayList list3 = multiCharlist();

    list1.clear();
    list2.clear();
    list3.clear();

    list1.print();
    list2.print();
    list3.print();
}

/* Tests expand function to make sure a list expands.
 * temporarily created a public function that allows
 * me to see if the expansion worked. 
 */
void expand_AL()
{
    CharArrayList list1;
    CharArrayList list2 = oneCharlist();
    CharArrayList list3 = multiCharlist();

    //list1.expand(); expand function was temporarily made public to test 
    //list2.expand(); however it is a private function so had to be
    //list3.expand(); commented out. All tests passed!
}

/* Tests shrink function to make sure a list shrinks.
 * temporarily created a public function that would allow
 * me to see if the shrinking worked. 
 */
void shrink_AL()
{
    CharArrayList list1;
    CharArrayList list2 = oneCharlist();
    CharArrayList list3 = multiCharlist();

    //list1.shrink(); shrink function was temporarily made public to 
    //list2.shrink(); test. ALl tests passed!
    //list3.shrink();

}

/* Test arraylist pushAtBack function 
 * prints lists before and after to make sure char 'x' was inserted
 * at the end of the list 
 */
void pushAtBack_AL()
{
    char x = 'x';

    CharArrayList list1;
    CharArrayList list2 = oneCharlist();
    CharArrayList list3 = multiCharlist();

    list1.print();
    list2.print();
    list3.print();

    std::cout << "Add 'x' to the back of list1, list2, and list3." 
              << std::endl;

    list1.pushAtBack(x);
    list2.pushAtBack(x);
    list3.pushAtBack(x);

    list1.print();
    list2.print();
    list3.print();
}

/* Test arraylist pushAtFront function 
 * prints lists before and after to make sure char 'x' was inserted
 * at the front of the list 
 */
void pushAtFront_AL()
{
    char x = 'x';

    CharArrayList list1;
    CharArrayList list2 = oneCharlist();
    CharArrayList list3 = multiCharlist();

    list1.print();
    list2.print();
    list3.print();

    std::cout << "Add 'x' to the front of list1, list2, and list3." 
              << std::endl;

    list1.pushAtFront(x);
    list2.pushAtFront(x);
    list3.pushAtFront(x);

    list1.print();
    list2.print();
    list3.print();
}

/* Test arraylist insertAt function 
 * prints lists before and after to make sure char 'x' was inserted
 * at the desired index 
 */
void insertAt_AL()
{
    char x = 'x';

    CharArrayList list1;
    CharArrayList list2 = oneCharlist();
    CharArrayList list3 = multiCharlist();

    list1.print();
    list2.print();
    list3.print();

    std::cout << "Add 'x' to index 1 of list2 and list3. "
              << "Add 'x' to index 0 of list1 (it's empty)." << std::endl;

    //list1.insertAt(x, 1); correctly fails. Index is out of range 0-size
    list1.insertAt(x, 0);
    list2.insertAt(x, 1);
    list3.insertAt(x, 1);
    //list3.insertAt(x, -5); correctly fails

    list1.print();
    list2.print();
    list3.print();
}

/* tests to remove a char from desired index 
 */
void removeAt_AL()
{
    CharArrayList list1;
    CharArrayList list2 = oneCharlist();
    CharArrayList list3 = multiCharlist();

    list1.print();
    list2.print();
    list3.print();

    //list1.removeAt(0); correctly fails
    //list1.print();

    std::cout << "Remove index 0 from list2." << std::endl;
    list2.removeAt(0);
    list2.print();

    std::cout << "Remove index 0, 2, and 4 from list3." << std::endl;
    list3.removeAt(0);
    list3.removeAt(1); //index 2 becomes 1 after first removal 
    list3.removeAt(2); //index 4 becomes 2 after two removals
    //list3.removeAt(10); correctly fails
    list3.print();
}

/* tests to replace a char from desired index 
 */
void replaceAt_AL()
{
    char x = 'x';

    CharArrayList list1;
    CharArrayList list2 = oneCharlist();
    CharArrayList list3 = multiCharlist();

    list1.print();
    list2.print();
    list3.print();

    //list1.replaceAt(0); correctly fails
    //list1.print();

    std::cout << "Replace index 0 from list2 and index 1 from list3 with 'x'" 
              << std::endl;
    list2.replaceAt(x, 0);
    list3.replaceAt(x, 1);
    //list3.replaceAt(x,10); correctly fails

    list2.print();
    list3.print();
}

/* concatenate test, make sure the elements of the list being passed in 
 * are added to end of the current list 
 *
 */
void concatenate_AL()
{
    CharArrayList list1;
    CharArrayList list2 = oneCharlist();
    CharArrayList list3 = multiCharlist();

    char cat[] = {'C','A','T'};
    char *arr = cat;
    CharArrayList catList(arr, 3);

    list1.print();
    list2.print();
    list3.print();

    std::cout << "Add CAT to the end of each list." << std::endl;

    list1.concatenate(catList);
    list2.concatenate(catList);
    list3.concatenate(catList);

    list1.print();
    list2.print();
    list3.print();
}

/* purpose: intitializes a one char list 
 * parameters: none 
 * returns: one char list 
 */
CharArrayList oneCharlist() 
{
    char c = 'a';
    CharArrayList list(c);

    return list;
}

/* purpose: intitializes a multi char list 
 * parameters: none 
 * returns: multi char list 
 */
CharArrayList multiCharlist() 
{
    char init[] = {'1','2','3','4','5'};
    char *arr = init;
    CharArrayList list(arr, 5);

    return list;
}
// initialize
// Test empty list
// Test one element list
// Test multi-element list
// Test edge cases

/*******************************************************************\
*                      CHAR LINKED LIST TESTS                       *
\*******************************************************************/

// helper functions to initialize one char and mulit char lists 
CharLinkedList oneCharlist_LL();
CharLinkedList multiCharlist_LL();

/* default constructor test
 * Run the LinkedList default constructor to make sure there are no runtime
 * errors or memory leaks
 */
void default_constructor_LL()
{
    CharLinkedList testLinkedList;
}

/*one char constructor test 
 * Run the LinkedList one char constructor to make sure it works properly
 */
void oneChar_constructor_LL()
{
    CharLinkedList list = oneCharlist_LL();
    
    assert(list.size() == 1);
    assert(not list.isEmpty());
    list.print();
}

/* multi char constructor test 
 * Run the LinkedList multi char constructor to make sure it works properly
 */
void multiChar_constructor_LL()
{
    CharLinkedList list = multiCharlist_LL();
    
    assert(list.size() == 5);
    assert(not list.isEmpty());
    list.print();
}

/* copy constructor test 
 * Run the LinkedList copy constructor to make sure it works properly
 */
void copyConstructor_LL()
{
    CharLinkedList list1 = multiCharlist_LL();
    CharLinkedList list2(list1);
    
    assert(list2.size() == 5);
    assert(not list2.isEmpty());
    list2.print();
    
}

/* assignment operator test 
 * Run the LinkedList assignment operator to make sure it works properly
 */
void assignmentOperator_LL()
{
    char init[] = {'c','o','C','A','T'};
    char *arr = init;
    CharLinkedList list2copy(arr, 5);
    
    CharLinkedList list2change = oneCharlist_LL();

    list2change = list2copy;
    
    assert(list2change.size() == 5);
    assert(not list2change.isEmpty());
    list2change.print();

}

/* Tests linked list size function 
 * make sure an empty list is empty and that non empty lists are not empty 
 */
void isEmpty_LL()
{
    CharLinkedList list1;
    CharLinkedList list2 = oneCharlist_LL();
    CharLinkedList list3 = multiCharlist_LL();
    
    assert(list1.isEmpty());
    assert(not list2.isEmpty());
    assert(not list3.isEmpty());
}

/* test to see if size function 
 * returns proper size for empty list,
 * one char list, and multi char list 
 */
void size_LL()
{
    CharLinkedList list1;
    CharLinkedList list2 = oneCharlist_LL();
    CharLinkedList list3 = multiCharlist_LL();

    assert(list1.size() == 0);
    assert(list2.size() == 1);
    assert(list3.size() == 5);

}

/* checks to see if "first" function works and returns the first element
 * of the list 
 */
void first_LL()
{
    CharLinkedList list1;
    CharLinkedList list2 = oneCharlist_LL();
    CharLinkedList list3 = multiCharlist_LL();

    //assert(list1.first()); correctly fails
    assert(list2.first() == 'a');
    assert(list3.first() == '1');
}

/* checks to see if "last" function works and returns the last element
 * of the list 
 */
void last_LL()
{
    CharLinkedList list1;
    CharLinkedList list2 = oneCharlist_LL();
    CharLinkedList list3 = multiCharlist_LL();

    //assert(list1.last());
    assert(list2.last() == 'a');
    assert(list3.last() == '5');
}

/* checks "elementAt" function 
 */
void elementAt_LL()
{
    CharLinkedList list1;
    CharLinkedList list2 = oneCharlist_LL();
    CharLinkedList list3 = multiCharlist_LL();

    //assert(list1.elementAt(0)); correctly fails
    assert(list2.elementAt(0) == 'a');
    assert(list3.elementAt(3) == '4');
    //assert(list3.elementAt(10) == '4'); correctly fails

}

/* tests print function to make sure it properly outputs the list 
 * in the correct order 
 */
void print_LL()
{
    CharLinkedList list1;
    CharLinkedList list2 = oneCharlist_LL();
    CharLinkedList list3 = multiCharlist_LL();

    list1.print();
    list2.print();
    list3.print();
}

/* Tests clear function to make sure a list is cleared an prints out the
 * result to make sure it is an empty list of size 0
 */
void clear_LL()
{
    CharLinkedList list1;
    CharLinkedList list2 = oneCharlist_LL();
    CharLinkedList list3 = multiCharlist_LL();

    list1.clear();
    list2.clear();
    list3.clear();

    list1.print();
    list2.print();
    list3.print();
}

/* Test arraylist pushAtBack function 
 * prints lists before and after to make sure char 'x' was inserted
 * at the end of the list 
 */
void pushAtBack_LL()
{
    char x = 'x';

    CharLinkedList list1;
    CharLinkedList list2 = oneCharlist_LL();
    CharLinkedList list3 = multiCharlist_LL();

    list1.print();
    list2.print();
    list3.print();

    std::cout << "Add 'x' to the back of list1, list2, and list3." 
              << std::endl;

    list1.pushAtBack(x);
    list2.pushAtBack(x);
    list3.pushAtBack(x);

    list1.print();
    list2.print();
    list3.print();
}

/* Test arraylist pushAtFront function 
 * prints lists before and after to make sure char 'x' was inserted
 * at the front of the list 
 */
void pushAtFront_LL()
{
    char x = 'x';

    CharLinkedList list1;
    CharLinkedList list2 = oneCharlist_LL();
    CharLinkedList list3 = multiCharlist_LL();

    list1.print();
    list2.print();
    list3.print();

    std::cout << "Add 'x' to the front of list1, list2, and list3." 
              << std::endl;

    list1.pushAtFront(x);
    list2.pushAtFront(x);
    list3.pushAtFront(x);

    list1.print();
    list2.print();
    list3.print();
}

/* Test Linkedlist insertAt function 
 * prints lists before and after to make sure char 'x' was inserted
 * at the desired index 
 */
void insertAt_LL()
{
    char x = 'x';

    CharLinkedList list1;
    CharLinkedList list2 = oneCharlist_LL();
    CharLinkedList list3 = multiCharlist_LL();

    list1.print();
    list2.print();
    list3.print();

    std::cout << "Add 'x' to index 1 of list2 and list3. "
              << "Add 'x' to index 0 of list1 (it's empty)." << std::endl;

    //list1.insertAt(x, 1); correctly fails. Index is out of range 0-size
    list1.insertAt(x, 0);
    list2.insertAt(x, 1);
    list3.insertAt(x, 1);
    //list3.insertAt(x, -5); correctly fails

    list1.print();
    list2.print();
    list3.print();
}

/* test popFromFront function to make sure it removes the first element
 * of the list 
 */
void popFromFront_LL()
{
    //CharLinkedList list1; empty list fails to pop 
    CharLinkedList list2 = oneCharlist_LL();
    CharLinkedList list3 = multiCharlist_LL();
    
    //list1.print();
    list2.print();
    list3.print();
    
    std::cout << "remove first element of each list." << std::endl;
    
    //list1.popFromFront(); correctly fails
    list2.popFromFront();
    list3.popFromFront();
    
    //list1.print();
    list2.print();
    list3.print();
}

/* test popFromBack function to make sure it removes the last element
 * of the list 
 */
void popFromBack_LL()
{
    //CharLinkedList list1; empty list fails to pop 
    CharLinkedList list2 = oneCharlist_LL();
    CharLinkedList list3 = multiCharlist_LL();
    
    //list1.print();
    list2.print();
    list3.print();
    
    std::cout << "remove last element of each list." << std::endl;
    
    //list1.popFromFront(); correctly fails
    list2.popFromBack();
    list3.popFromBack();
    
    //list1.print();
    list2.print();
    list3.print();
}

/* tests to remove a char from desired index 
 */
void removeAt_LL()
{
    CharLinkedList list1;
    CharLinkedList list2 = oneCharlist_LL();
    CharLinkedList list3 = multiCharlist_LL();

    list1.print();
    list2.print();
    list3.print();

    //list1.removeAt(0); correctly fails
    //list1.print();

    std::cout << "Remove index 0 from list2." << std::endl;
    list2.removeAt(0);
    list2.print();

    std::cout << "Remove index 0, 2, and 4 from list3." << std::endl;
    list3.removeAt(0);
    list3.removeAt(1); //index 2 becomes 1 after first removal 
    list3.removeAt(2); //index 4 becomes 2 after two removals
    //list3.removeAt(10); correctly fails
    list3.print();
}

/* tests to replace a char from desired index 
 */
void replaceAt_LL()
{
    char x = 'x';

    CharLinkedList list1;
    CharLinkedList list2 = oneCharlist_LL();
    CharLinkedList list3 = multiCharlist_LL();

    list1.print();
    list2.print();
    list3.print();

    //list1.replaceAt(0); correctly fails
    //list1.print();

    std::cout << "Replace index 0 from list2 and index 1 from list3 with 'x'" 
              << std::endl;
    list2.replaceAt(x, 0);
    list3.replaceAt(x, 1);
    //list3.replaceAt(x,10); correctly fails

    list2.print();
    list3.print();
}

/* concatenate test, make sure the elements of the list being passed in 
 * are added to end of the current list 
 *
 */
void concatenate_LL()
{
    CharLinkedList list1;
    CharLinkedList list2 = oneCharlist_LL();
    CharLinkedList list3 = multiCharlist_LL();

    char cat[] = {'C','A','T'};
    char *arr = cat;
    CharLinkedList catList(arr, 3);

    list1.print();
    list2.print();
    list3.print();

    std::cout << "Add CAT to the end of each list." << std::endl;

    list1.concatenate(catList);
    list2.concatenate(catList);
    list3.concatenate(catList);

    list1.print();
    list2.print();
    list3.print();
}

/* purpose: intitializes a one char list 
 * parameters: none 
 * returns: one char list 
 */
CharLinkedList oneCharlist_LL() 
{
    char c = 'a';
    CharLinkedList list(c);
    
    return list;
}

/* purpose: intitializes a mulit char list 
 * parameters: none 
 * returns: multi char list 
 */
CharLinkedList multiCharlist_LL() 
{
    char init[] = {'1','2','3','4','5'};
    char *arr = init;
    CharLinkedList list(arr, 5);
    
    return list;
}

