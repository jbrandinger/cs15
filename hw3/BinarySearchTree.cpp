/* Joel Brandinger
 * BinarySearchTree.cpp
 * COMP15
 * Spring 2021
 *
 * Implementation of the Binary Search Tree class.
 * Behaves like a standard BST except that it handles multiplicity
 * If you insert a number twice  and then remove it once, then it will
 * still be in the data structure
 */

#include <cstring>
#include <iostream>
#include <limits>

#include "BinarySearchTree.h"

using namespace std;

// default constructor 
BinarySearchTree::BinarySearchTree()
{
        root = nullptr;
}
 // destructor
BinarySearchTree::~BinarySearchTree()
{
        // walk tree in post-order traversal and delete
        post_order_delete(root);
        root = nullptr;  // not really necessary, since the tree is going
                         // away, but might want to guard against someone
                         // using a pointer after deleting
}

/* post_order_delete(Node *node)
 *
 * Purpose: walk tree in post-order traversal and delete all nodes 
 * Parameters: root of tree/ subtree 
 */
void BinarySearchTree::post_order_delete(Node *node)
{
        if (node == nullptr) {
            return;
        } else {
            post_order_delete(node->left);
            post_order_delete(node->right);
            delete node;
        }
}

// copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source)
{
        // use pre-order traversal to copy the tree
        root = pre_order_copy(source.root);
}

// assignment overload
BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &source)
{
        if (this != &source) {
            post_order_delete(root);
            root = pre_order_copy(source.root);
        }
        return *this;
}

/* pre_order_copy(Node *node) const
 *
 * Purpose: walk tree in pre-order traversal and copy all the nodes
 * Parameters: root of tree/ subtree 
 * Returns: root of the copied tree 
 */ 
BinarySearchTree::Node *BinarySearchTree::pre_order_copy(Node *node) const
{
        if (node == nullptr) {
            return node;
        }
        Node *toCopy = new Node;
        toCopy->data = node->data;
        toCopy->count = node->count;
        toCopy->left = pre_order_copy(node->left);
        toCopy->right = pre_order_copy(node->right);
        
        return toCopy;
}

// find smallest value in the tree using private helper function 
int BinarySearchTree::find_min() const
{
        if (root == nullptr)
                return numeric_limits<int>::max(); // INT_MAX

        return find_min(root)->data;
}

/* find_min(Node *node)
 *
 * Purpose: find smalest value in the tree 
 * Paramters: root of tree/ subtree 
 * Returns: smallest Node 
 */
BinarySearchTree::Node *BinarySearchTree::find_min(Node *node) const
{
        if (node == nullptr) {
            return node;
        } else if (node->left == nullptr) {
            return node;
        } else {
            return find_min(node->left);
        }
}

// find largest value in the tree using private helper function 
int BinarySearchTree::find_max() const
{
    if (root == nullptr)
            return numeric_limits<int>::min(); // INT_MIN

    return find_max(root)->data;
}

/* find_max(Node *node)
 *
 * Purpose: find largest value in the tree 
 * Paramters: root of tree/ subtree 
 * Returns: largest Node 
 */
BinarySearchTree::Node *BinarySearchTree::find_max(Node *node) const
{
    if (node == nullptr) {
        return node;
    } else if (node->right == nullptr) {
        return node;
    } else {
        return find_max(node->right);
    }
}

// check if a given value is in the tree using a private helper function 
bool BinarySearchTree::contains(int value) const
{
        return contains(root, value);
}

/* contains(Node *node, int value) const
 *
 * Purpose: check if the given value is in the tree  
 * Paramters: root of tree/ subtree and the value to check 
 * Returns: true if value is found, false otherwise
 */
bool BinarySearchTree::contains(Node *node, int value) const
{
        if (node == nullptr) {
            return false;
        } else if (node->data == value) {
            return true;
        } else if (value < node->data) {
            return contains(node->left, value);
        } else {
            return contains(node->right, value);
        }
}
// insert new node into the tree using private helper function 
void BinarySearchTree::insert(int value)
{
        root = insert(root, value);
}

/* insert(Node *node, int value)
 *
 * Purpose: insert a new node/ value into the tree   
 * Paramters: root of tree/ subtree and the value to be inserted 
 * Returns: pointer to root of tree with new Node inserted 
 */
BinarySearchTree::Node *BinarySearchTree::insert(Node *node, int value)
{
        if (node == nullptr) {
            return newNode(value);
        } else if (value == node->data) {
            node->count++;
            return node;
        } else if (value < node->data) {
            node->left = insert(node->left, value);
            return node;
        } else {
            node->right = insert(node->right, value);
            return node;
        }
}

/* newNode(int value)
 *
 * Pupose: create a new node with the desired value
 * Parameters: value of the node 
 * Returns: the new node 
 */
BinarySearchTree::Node *BinarySearchTree::newNode(int value)
{
        Node *new_node = new Node;
        new_node->data = value;
        new_node->count = 1;
        new_node->left = nullptr;
        new_node->right = nullptr;
        
        return new_node;
}

// remove a node from the tree using a private helper function 
bool BinarySearchTree::remove(int value)
{
        return remove(root, value);
}

/* remove(Node *node, int value)
 *
 * Purpose: remove the desired value from the tree, if it is a duplicate
 *          decrease its count 
 * Paramters: root of tree/ subtree and value to be removed 
 * Returns: true if value is removed, false otherwise
 */
bool BinarySearchTree::remove(Node *node, int value)
{
        // check if tree is empty 
        if (node == nullptr) {
            return false;
        } 
        // check if the value is in the tree 
        else if (!contains(value)) {
            return false;
        }
        // check if root (special case because no parents)
        else if (value == root->data) {
            rootDelete();
            return true;
        }
        else {
            Node *toRemove = findNode(root, value);
            Node *parent = find_parent(root, toRemove);
            // if duplicate, decrease count 
            if (toRemove->count > 1) {
                toRemove->count--; 
            } 
            else {
                if (noChildren(toRemove)) {
                        noChildRemoval(toRemove, parent);
                } else if (oneChild(toRemove)) {
                    oneChildRemoval(toRemove, parent);
                } else {
                    twoChildRemoval(toRemove);
                }
            }
            return true;
        }        
}

/* rootDelete()
 *
 * Purpose: delete the root of the tree, special case since the root has
 *          no parents 
 */ 
void BinarySearchTree::rootDelete()
{
    if (root->count > 1) {
        root->count--;
    }
    else if ((root->left == nullptr) and (root->right == nullptr)) {
        delete root;
        root = nullptr;
    } 
    else if (root->right == nullptr) {
        Node *temp = root;
        root = temp->left;
        delete temp;
    }
    else if (root->left == nullptr) {
        Node *temp = root;
        root = temp->right;
        delete temp;
    }
    else {
        twoChildRemoval(root);
    }
}
/* noChildren(Node *toRemove)
 *
 * Purpose: check if a given node has no children  
 * Parameters: node to check 
 * Returns: true if node has no children, false otherwise 
 */
bool BinarySearchTree::noChildren(Node *toRemove)
{
        if ((toRemove->left == nullptr) and (toRemove->right == nullptr)) {
            return true;
        } else {
            return false;
        }
}

/* noChildRemoval(Node *toRemove, Node *parent)
 * 
 * Purpose: delete a node with no children 
 * Parameters: node to be removed and its parent 
 */
void BinarySearchTree::noChildRemoval(Node *toRemove, Node *parent)
{
        delete toRemove;
        
        if (parent->left == toRemove) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
}

/* oneChild(Node *toRemove)
 *
 * Purpose: check if a given node has one child 
 * Parameters: node to check 
 * Returns: true if node has one child, false otherwise 
 */
bool BinarySearchTree::oneChild(Node *toRemove)
{
        if ((toRemove->left == nullptr) or (toRemove->right == nullptr)) {
            return true;
        } else {
            return false;
        }
}

/* oneChildRemoval(Node *toRemove, Node *parent)
 * 
 * Purpose: delete a node with one child
 * Parameters: node to be removed and its parent 
 */
void BinarySearchTree::oneChildRemoval(Node *toRemove, Node *parent)
{
        // one right child 
        if (toRemove->left == nullptr) {
            if (parent->left == toRemove) {
                parent->left = toRemove->right;
            } else {
                parent->right = toRemove->right;
            }
            delete toRemove;
        }
        // one left child
        else {
            if (parent->left == toRemove) {
                parent->left = toRemove->left;
            } else {
                parent->right = toRemove->left;
            }
            delete toRemove;
    }
}
/* twoChildRemoval(Node *toRemove)
 * 
 * Purpose: delete a node with two children 
 * Parameters: node to be removed
 */
void BinarySearchTree::twoChildRemoval(Node *toRemove)
{
        Node *temp = find_min(toRemove->right);
        int temp_data = temp->data;
        int temp_count = temp->count;
        if (temp->count > 1) {
            temp->count = 1;
        }
        remove(temp->data);
        toRemove->data = temp_data;
        toRemove->count = temp_count;
}

/* findNode(Node *node, int value)
 *
 * Purpose: find the node with the given value 
 * Parameters: root of tree/ subtree and value to be found
 * Returns: the node to be found
 */
BinarySearchTree::Node *BinarySearchTree::findNode(Node *node, int value)
{
        if (node == nullptr) {
            return nullptr;
        } else if (node->data == value) {
            return node;
        } else if (value < node->data) {
            return findNode(node->left, value);
        } else {
            return findNode(node->right, value);
        }
}

// find the height of the tree using a private helper function 
int BinarySearchTree::tree_height() const
{
        return tree_height(root);
}

/* tree_height(Node *node) const
 *
 * Purpose: find the height of the tree 
 * Parameters: root of tree/ subtree
 * Returns: tree height 
 */
int BinarySearchTree::tree_height(Node *node) const
{
        if (node == nullptr) {
            return -1;
        } else {
            return 1 + max(tree_height(node->left), tree_height(node->right));
        }
}

// returns the total number of nodes
int BinarySearchTree::node_count() const
{
        return node_count(root);
}

/* node_count(Node *node) const
 *
 * Purpose: count the number of nodes in the tree 
 * Parameters: root of tree/ subtree
 * Returns: number of nodes in the tree 
 */
int BinarySearchTree::node_count(Node *node) const
{
        if (node == nullptr) {
            return 0;
        } else {
            return 1 + node_count(node->left) + node_count(node->right);
        }
}

// return the sum of all the node values (including duplicates)
int BinarySearchTree::count_total() const
{
        return count_total(root);
}

/* count_total(Node *node) const
 *
 * Purpose: sum all the values in the tree including duplicates 
 * Parameters: root of tree/ subtree
 * Returns: total count of all the values 
 */
int BinarySearchTree::count_total(Node *node) const
{
        if (node == nullptr) {
            return 0;
        } else {
            return (node->data * node->count) + count_total(node->left)
                                              + count_total(node->right);
        }
}

BinarySearchTree::Node *BinarySearchTree::find_parent(Node *node,
                                                      Node *child) const
{
        if (node == nullptr)
                return nullptr;

        // if either the left or right is equal to the child,
        // we have found the parent
        if (node->left == child or node->right == child) {
                return node;
        }

        // Use the binary search tree invariant to walk the tree
        if (child->data > node->data) {
                return find_parent(node->right, child);
        } else {
                return find_parent(node->left, child);
        }
}

// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() const
{
        size_t      numLayers  = tree_height() + 1;
        size_t      levelWidth = 4;
        const char *rootPrefix = "-> ";

        // Need numLayers * levelWidth characters for each layer of tree.
        // Add an extra levelWidth characters at front to avoid if statement
        // 1 extra char for nul character at end
        char *start = new char[(numLayers + 1) * levelWidth + 1];

        print_tree(root, start + levelWidth, start + levelWidth, rootPrefix);
        delete[] start;
}

// Logic and Output Reference: 
// https://www.techiedelight.com/c-program-print-binary-tree/
void BinarySearchTree::print_tree(Node *node, char *const currPos,
                                  const char *const fullLine,
                                  const char *const branch) const
{
        if (node == nullptr)
                return;

        // 4 characters + 1 for nul terminator
        using TreeLevel                    = char[5];
        static const int       levelLength = sizeof(TreeLevel) - 1;
        static const TreeLevel UP = ".-- ", DOWN = "`-- ", EMPTY = "    ",
                               CONNECT = "   |";
        // Copies prev into dest and advances dest by strlen(prev)
        auto set = [](char *dest, const char *prev) {
                size_t p = strlen(prev);
                return (char *)memcpy(dest, prev, p) + p;
        };

        print_tree(node->right, set(currPos, EMPTY), fullLine, UP);

        // Clear any characters that would immediate precede the "branch"
        // Don't need to check for root (i.e start of array),fullLine is padded
        set(currPos - levelLength, EMPTY);

        // Terminate fullLine at current level
        *currPos = '\0';

        std::cerr << fullLine << branch << node->data
                  << (node->count > 1 ? "*" : "") << endl;

        // Connect upper branch to parent
        if (branch == UP)
                set(currPos - levelLength, CONNECT);

        // Connect lower branch to parent
        print_tree(node->left, set(currPos, CONNECT), fullLine, DOWN);
}
