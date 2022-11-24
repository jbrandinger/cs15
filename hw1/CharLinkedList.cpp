/* 
 * CharLinkedList.cpp
 * 
 * COMP 15 homework 1
 * by C.R. Calabrese, January 2021
 * edited by [Joel Brandinger], [28 September 2021]
 * 
 * Stores characters in a certain order. It imitates some functions of the
 * C++ string. 
 * 
 * NOTE: This is implemented using a doubly-linked list. It is not circular
 *       and does not have a "back" pointer.
 */

#include "CharLinkedList.h"

// for the print function
#include <iostream>

using namespace std;

/* Purpose: initializes an empty CharLinkedList */
CharLinkedList::CharLinkedList()
{
    front = nullptr;
    len = 0;
}

/*    Purpose: initializes a CharLinkedList containing one character
 * Parameters: the character that should be stored in the new list
 */
CharLinkedList::CharLinkedList(char c)
{
    front = createNode(c);
    len = 1;
    
}

/*    Purpose: initializes a CharLinkedList containing all of the specified 
 *             characters, in the given order
 * Parameters: An array (in order) of characters to be stored in the list;
 *             the length of the given array (as an int)
 */
 CharLinkedList::CharLinkedList(char *arr, int size)
 {
     front = createNode(arr[0]);
     len = 1;
     
     for (int i = 1; i < size; i++) {
         pushAtBack(arr[i]);
     } 
 
 }

/* purpose: creates a new node 
 * Paramaters: a char to store as data 
 * returns: a new Node 
 */
CharLinkedList::Node *CharLinkedList::createNode(char c)
{
    Node *new_node = new Node;
    new_node->data = c;
    new_node->next = nullptr;
    
    return new_node;
    
}

/* Purpose: copy constructor -- creates a list with the same information as
 *          the one passed in
 */
CharLinkedList::CharLinkedList(const CharLinkedList &other) 
{
    front = createNode(other.elementAt(0));
    len = 1;
    // push each item from the other list onto this one
    for (int i = 1; i < other.size(); i++) {
        pushAtBack(other.elementAt(i));
    }
}

/* Purpose: destructor -- frees all memory associated with the list */
CharLinkedList::~CharLinkedList()
{    
    while (front != nullptr) {
        popFromFront();
    }
}

/* Purpose: assignment operator -- makes the current list contain the same
 *          information as the one on the right hand side
 */
CharLinkedList &CharLinkedList::operator =(const CharLinkedList &rhs) 
{
    if (this != &rhs) {
        clear(); // clear the current list
        
        // add each element from the other list into this one
        for (int i = 0; i < rhs.size(); i++) {
            pushAtBack(rhs.elementAt(i));
        }
    }
    return *this;
}

/* isEmpty
 *    Purpose: Check if the list is empty
 * Parameters: none
 *    Returns: a boolean -- true if the list is empty, false if it isn't
 */
bool CharLinkedList::isEmpty() const 
{
    return (front == nullptr);
}

/* size
 *    Purpose: Get the number of characters being stored in the list
 * Parameters: none
 *    Returns: The number of characters currently stored in the list, as an
 *             int (will never be negative)
 */
int CharLinkedList::size() const 
{
    return len;
}

/* first
 *    Purpose: Get the first element in the list.
 * Parameters: none
 *    Returns: The first element in the list, as a char.
 * 
 *       Note: Prints an error message and exits if the list is empty.
 */
char CharLinkedList::first() const 
{
    if (isEmpty()) {
        cerr << "Cannot return first from an empty list" << endl;
        exit(EXIT_FAILURE);
    }
    
    return front->data;
}

/* last
 *    Purpose: Get the last element in the list.
 * Parameters: none
 *    Returns: The last element in the list, as a char.
 * 
 *       Note: Prints an error message and exits if the list is empty.
 */
char CharLinkedList::last() const 
{
    if (isEmpty()) {
        cerr << "Cannot return last from an empty list" << endl;
        exit(EXIT_FAILURE);
    }
    return elementAt(len - 1);
}

/* elementAt
 *    Purpose: Get the character at a given position.
 * Parameters: The index to be accessed, as an int. Should be in bounds; in 
 *             other words, should be in the range [0, size() )
 *    Returns: The element at the specified index, as a char
 *
 *       Note: prints an error and exits if given index is out of range.
 */
char CharLinkedList::elementAt(int idx) const
{
    if (idx < 0 or idx > size()) {
        cerr << "index " << idx << " not in range [0.." << size() << ")"
             << endl;
        exit(EXIT_FAILURE);
    }
    
    if (isEmpty()) {
        cerr << "Cannot return index " << idx << " from an empty list" 
             << endl;
        exit(EXIT_FAILURE);
    }
    
    Node *curr = front;
    int counter = 0;
    
    while (counter != idx) {
        counter++;
        curr = curr->next;
    }  
    return curr->data;
}

/* print
 *    Purpose: Prints the list to the terminal (cout)
 * Parameters: None
 *    Returns: None
 */
void CharLinkedList::print() const
{
    Node *curr = front;

    cout << "[CharLinkedList of size " << size() <<  " <<";
    
    while (curr != nullptr) {
            cout << curr->data;
            curr = curr->next;
    }
    cout << ">>]" << endl;
}

/* clear
 *    Purpose: Makes the list empty
 * Parameters: None
 *    Returns: None
 */
void CharLinkedList::clear() 
{
    while (front != nullptr) {
        popFromFront();
    }
}

/* pushAtBack
 *    Purpose: Adds a character to the back of the list
 * Parameters: The character to be added to the list
 *    Returns: None
 */
void CharLinkedList::pushAtBack(char c)
{    
    if (isEmpty()) {
        front = createNode(c);
        len++;
        return;
    }
    
    Node *curr = front;
    
    while(curr != nullptr) {
        if(curr->next == nullptr) {
            Node *newNode = createNode(c);
            curr->next = newNode;
            len++;
            return;
        }
        curr = curr->next;
    }
}

/* pushAtFront
 *    Purpose: Adds a character to the front of the list
 * Parameters: The character to be added to the list
 *    Returns: None
 */
void CharLinkedList::pushAtFront(char c)
{
    if (isEmpty()) {
        front = createNode(c);
        len++;
    } else {
        Node *newNode = createNode(c);
        newNode->next = front;
        front = newNode;
        len++;
    }
}

/* insertAt
 *    Purpose: Adds a character to the list at a given position
 * Parameters: The character to be added to the list and the position at which
 *             it should be added. The position should be in-bounds, that is,
 *             in the range [0, size()]. Providing size() as the index will
 *             insert the character at the back of the list.
 *    Returns: None
 *
 *       Note: prints an error and exits if given index is out of range.
 * 
 *      To-Do: Would be fun to figure out how to do this recursively -- prev
 *             pointer makes it a little more complicated
 */
void CharLinkedList::insertAt(char c, int idx)
{
    // confirm index is in range
    if (idx < 0 or idx > size()) {
        cerr << "index " << idx << " not in range [0.." << size() << ")"
             << endl;
        exit(EXIT_FAILURE);
    }
    
    if (isEmpty() or idx == 0) {
        pushAtFront(c);
        return;
    }
    
    Node *prev = front;
    Node *curr = front->next;
    int counter = 1;
    
    while (counter != idx) {
        counter++;
        curr = curr->next;
        prev = prev->next;
    }
    Node *newNode = createNode(c);
    newNode->next = curr;
    prev->next = newNode;
    len++;    
}

/* popFromFront
 *    Purpose: Removes the first element from the list
 * Parameters: None
 *    Returns: None
 *       Note: Prints an error message and exits if the list is empty
 */
void CharLinkedList::popFromFront()
{
    if (isEmpty()) {
        cerr << "Cannot pop from an empty list" << endl;
        exit(EXIT_FAILURE);
    }
    
    Node *newFront;
    newFront = front->next;
    delete front;
    front = newFront;
    len--;
}

/* popFromBack
 *    Purpose: Removes the last element from the list
 * Parameters: None
 *    Returns: None
 *       Note: Prints an error message and exits if the list is empty
 */
void CharLinkedList::popFromBack()
{
    if (isEmpty()) {
        cerr << "Cannot pop from an empty list" << endl;
        exit(EXIT_FAILURE);
    }
    
    removeAt(len - 1);
}

/* removeAt
 *    Purpose: Removes the element at a given index
 * Parameters: The position at which to remove an element, which should be the
 *             index of an element currently in the list; in other words,
 *             should be in the interval [0, size)
 *    Returns: None
 */
void CharLinkedList::removeAt(int idx)
{
    // confirm index is in range
    if (idx < 0 or idx >= size()) {
        cerr << "index " << idx << " not in range [0.." << size() << ")"
             << endl;
        exit(EXIT_FAILURE);
    }
    
    if (idx == 0) {
        popFromFront();
        return;
    }
    
    Node *curr = front;
    Node *toDelete = front->next;
    int counter = 1;
    
    while (counter != idx) {
        counter++;
        curr = curr->next;
        toDelete = toDelete->next;
    }
    curr->next = toDelete->next;
    delete toDelete;
    len--;
}

/* replaceAt
 *    Purpose: Replaces the element at the given index with the given value
 * Parameters: A character to put in the list and the index of the
 *             element to replace. The index should be in-bounds, in the
 *             range [0, size() )
 *       Note: Prints an error message and exits if the index is out of bounds
 */
void CharLinkedList::replaceAt(char c, int idx)
{
    // confirm index is in range
    if (idx < 0 or idx >= size()) {
        cerr << "index " << idx << " not in range [0.." << size() << ")"
             << endl;
        exit(EXIT_FAILURE);
    }
    
    insertAt(c, idx);
    removeAt(idx + 1);
}

/* concatenate
 *    Purpose: Adds the contents of a CharLinkedList to the back of the current 
 *             one.
 * Parameters: A CharLinkedList whose contents should be pushed to the back of 
 *             the current list. Will not be altered
 *    Returns: None
 */
void CharLinkedList::concatenate(const CharLinkedList &other)
{
    for (int i = 0; i < other.size(); i++) {
        pushAtBack(other.elementAt(i));
    }
}
