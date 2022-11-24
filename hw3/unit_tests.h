/* unit_tests.h
 *
 * Purpose: tests all the functions of BinarySearchTree.cpp 
 * 
 * Created By: Joel Brandinger
 * Date: November 2021
 */
 
#include "BinarySearchTree.h"
#include <cassert>
using namespace std;

// default contstructor
void default_constructor()
{
    BinarySearchTree bst;
}

// create BinarySearchTree for testing 
BinarySearchTree createTree1()
{
    BinarySearchTree bst;
    int values[] = {4, 2, 1, 3, 6, 5, 7};
    int numValues = sizeof(values) / sizeof(int);
    
    for (int i = 0; i < numValues; i++) {
            bst.insert(values[i]);
    }
    return bst;
}

// create BinarySearchTree for testing 
BinarySearchTree createTree2()
{
    BinarySearchTree bst;
    int values[] = {11, 9, 8, 10, 13, 12, 14};
    int numValues = sizeof(values) / sizeof(int);
    
    for (int i = 0; i < numValues; i++) {
            bst.insert(values[i]);
    }
    return bst;
}

// create BinarySearchTree for testing 
BinarySearchTree largeTree()
{
    BinarySearchTree bst;
    int values[] = {20, 10, 30, 5, 15, 25, 35, 32, 48, 72, -2, 3, 12, 14, 11};
    int numValues = sizeof(values) / sizeof(int);
    
    for (int i = 0; i < numValues; i++) {
            bst.insert(values[i]);
    }
    return bst;
}
// copy contstructor
void copy_constructor()
{
    BinarySearchTree bst = createTree1();
    cerr << "Original tree: " << endl;
    bst.print_tree();

    BinarySearchTree bst_copy_constructor = bst;
    cerr << "Copied tree: " << endl;
    bst_copy_constructor.print_tree();
}

//assignment operator
void assignment_operator()
{
    BinarySearchTree bst1 = createTree1();
    cerr << "Tree 1: " << endl;
    bst1.print_tree();

    BinarySearchTree bst2 = createTree2();
    cerr << "Tree 2: " << endl;
    bst2.print_tree();

    cerr << "Assign tree 1 to tree 2 and print new tree 1: " << endl;
    bst1 = bst2;
    bst1.print_tree();
}

// find min 
void find_smallest()
{
    BinarySearchTree bst1 = createTree1();
    BinarySearchTree bst2 = createTree2();
    BinarySearchTree bstL = largeTree();

    int x = bst1.find_min();
    int y = bst2.find_min();
    int z = bstL.find_min();

    assert(x == 1);
    //assert(x == 7); properly fails 
    assert(y == 8);
    //assert(y == 14); properlu fails
    assert(z == -2);
    //assert(z == 1); properly fails 
}

// find max 
void find_biggest()
{
    BinarySearchTree bst1 = createTree1();
    BinarySearchTree bst2 = createTree2();
    BinarySearchTree bstL = largeTree();
    
    int x = bst1.find_max();
    int y = bst2.find_max();
    int z = bstL.find_max();

    assert(x == 7);
    //assert(x == 9); properly fails 
    assert(y == 14);
    //assert(y == 22); properly fails 
    assert(z == 72);
    //assert (z == 84); properly fails
}

// contains
void find_value()
{
    BinarySearchTree bst1 = createTree1();
    BinarySearchTree bst2 = createTree2();

    assert(bst1.contains(2));
    assert(bst2.contains(9));
    //assert(bst1.contains(10)); properly fails 
    //assert(bst2.contains(5)); properly fails     
}

// insert 
void insert_new_val()
{
    BinarySearchTree bst1 = createTree1();
    cerr << "Original tree: " << endl;
    bst1.print_tree();

    bst1.insert(0);
    bst1.insert(5);
    bst1.insert(-10);
    bst1.insert(4);
    bst1.insert(22);

    cerr << "Insert 0, 5, -10, 4, & 22: " << endl;
    bst1.print_tree();
}

// test various cases of removing the root 
void remove_root()
{
    BinarySearchTree bst;
    bst.insert(1);
    cerr << "Original tree: " << endl;
    bst.print_tree();
    
    cerr << "Remove root: " << endl;
    bst.remove(1);
    bst.print_tree();
    
    bst.insert(1);
    bst.insert(2);
    cerr << "Original tree: " << endl;
    bst.print_tree();
    
    cerr << "Remove 1: " << endl;
    bst.remove(1);
    bst.print_tree();
    
    bst.insert(2);
    cerr << "Original tree: " << endl;
    bst.print_tree();
    
    cerr << "Remove one copy of 2: " << endl;
    bst.remove(2);
    bst.print_tree();
    
    bst.insert(1);
    bst.insert(3);
    cerr << "Original tree: " << endl;
    bst.print_tree();
    
    cerr << "Remove 2: " << endl;
    bst.remove(2);
    bst.print_tree();
}

// test various cases of removing a leaf 
void remove_leaf()
{
    BinarySearchTree bst1 = createTree1();
    cerr << "Original tree: " << endl;
    bst1.print_tree();
    
    cerr << "Attempting to remove all leaves: " << endl;
    bst1.remove(1);
    bst1.remove(3);
    bst1.remove(5);
    bst1.remove(7);
    bst1.print_tree();
    
    cerr << "Attempting to remove 2: " << endl;
    bst1.remove(2);
    bst1.print_tree();
    
    cerr << "Create another copy of 6 and attempt to remove it." << endl;
    cerr << "Original tree: " << endl;
    bst1.insert(6);
    bst1.print_tree();
    cerr << "Remove 6: " << endl;
    bst1.remove(6);
    bst1.print_tree();
    
}

// test various cases of removing a node with one child 
void remove_one_child_node()
{
    BinarySearchTree bst1 = createTree1();
    bst1.remove(3);
    bst1.remove(5);
    cerr << "Original tree: " << endl;
    bst1.print_tree();
    
    cerr << "Remove 6: " << endl;
    bst1.remove(6);
    bst1.print_tree();
    
    cerr << "Remove 2: " << endl;
    bst1.remove(2);
    bst1.print_tree();
}

// test various cases of removing a node with two children 
void remove_node_with_two_children()
{
    BinarySearchTree bst2 = createTree2();
    cerr << "Original tree: " << endl;
    bst2.print_tree();
    
    cerr << "Remove 9 & 13: " << endl;
    bst2.remove(9);
    bst2.remove(13);
    bst2.print_tree();
    
    BinarySearchTree bstL = largeTree();
    cerr << "Original tree: " << endl;
    bstL.print_tree();
    
    cerr << "Remove 10: " << endl;
    bstL.remove(10);
    bstL.print_tree();
    
    cerr << "Remove 35: " << endl;
    bstL.remove(35);
    bstL.print_tree();
    
    cerr << "Remove 20: " << endl;
    bstL.remove(20);
    bstL.print_tree();
}