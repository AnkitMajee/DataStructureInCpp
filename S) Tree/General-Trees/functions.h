#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;

//Implement the TreeNode class
//Data Members:

class TreeNode
{
private:
    int data; //The value stored in the node.
    TreeNode** children; //Dynamic array pointer.
    int childrenCount; //Current children count.
    int capacity;
public:
    
TreeNode(int value); //Constructor to initialize the node with a given value.
~TreeNode(); // Destructor
TreeNode* getChild(int index); //Returns a pointer to the child.
void setChild(int index, TreeNode* desiredNode);
int getData(); // returns the data stored in the node.
void setData(int d); // sets the data of child
void addChild(TreeNode* node); //Adds a new child. Must handle array **resizing** (doubling capacity) if childrenCount reaches capacity.
int getChildrenCount(); // gets children count
void setChildrenCount(int n); // sets the children count
friend class Tree;
};

class Tree
{
private:
TreeNode* root; //Pointer to the root node of the tree.

public:
Tree(); //Constructor to initialize the tree.
~Tree(); // Destructor
void insertNode(int parentData, int value); //Finds parent node, and adds the new node as its last child.
TreeNode* findNode(int data); //Finds and returns the node with the data otherwise return nullptr.
TreeNode* findParent(int index); //finds parent
TreeNode* getRoot(); //Returns the root node of the tree.
int getHeight(int data); //Returns the height (the length of the longest path from this node to a leaf) of the node containing the given data.
int getDegree(int data); // Returns the degree (the number of children) of the node containing the given data.
void print_pre0rder(); // Prints the tree nodes' data using pre-order traversal (Root, Left, Right).
};



#endif
