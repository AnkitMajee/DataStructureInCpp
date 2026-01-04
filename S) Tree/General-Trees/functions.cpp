#include "functions.h"

// Constructor to initialize the node with a given value.
TreeNode::TreeNode(int value)
{
    data = value;
    childrenCount = 0;
    capacity = 10;
    children = new TreeNode *[capacity];
} 

// Destructor
TreeNode::~TreeNode(){
   for (int i = 0; i < childrenCount; i++)
   {
      delete children[i];
      children[i] = nullptr;
   }
   delete[] children;
   
}

// Returns a pointer to the child.
TreeNode *TreeNode::getChild(int index)
{
    return children[index];
} 

// sets child of node
void TreeNode::setChild(int index, TreeNode *desiredNode)
{
    children[index] = desiredNode;
}

 // returns the data stored in the node.
int TreeNode::getData()
{
    return data;
}

// sets data for node
void TreeNode::setData(int n)
{
    data = n;
} 

// returns the children count of node
int TreeNode::getChildrenCount()
{
    return childrenCount;
} 

// sets the children count of node
void TreeNode::setChildrenCount(int n)
{
    childrenCount = n;
} 

// Adds a new child
void TreeNode::addChild(TreeNode *node)
{
    if (childrenCount == capacity)
    {
        capacity *= 2;
        TreeNode **childrenTemp = new TreeNode *[capacity];
        for (int i = 0; i < childrenCount; i++)
        {
            childrenTemp[i] = children[i];
        }
        delete children;
        children = childrenTemp;
    }
    children[childrenCount] = node;
    childrenCount++;
} 


// -------------------  Trees Implementation -------------------------

// Constructor to initialize the tree.
Tree::Tree()
{
    root = nullptr;
} 

// Destructor
Tree::~Tree(){
   root = nullptr;
}

// Returns the root node of the tree.
TreeNode *Tree::getRoot()
{
    return root;
} 

// Insert Node Helper Function
TreeNode *insertNodeHelperFn(TreeNode *node, int parentData)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->getData() == parentData)
    {
        return node;
    }
    for (int i = 0; i < node->getChildrenCount(); i++)
    {
        TreeNode *searchNode = insertNodeHelperFn(node->getChild(i), parentData);
        if (searchNode != nullptr)
        {
            return searchNode;
        }
    }
    return nullptr;
}

// Insert Node in tree
void Tree::insertNode(int parentData, int value)
{
    TreeNode *parentNode;
    TreeNode *childNode = new TreeNode(value);
    if (root == nullptr)
    {
        parentNode = new TreeNode(parentData);
        root = parentNode;
    }
    parentNode = insertNodeHelperFn(root, parentData);
    if (parentNode == nullptr)
    {
        cout << "Parent Node not Found!" << endl;
        return;
    }
    int parentIndex = parentNode->getChildrenCount();
    parentNode->addChild(childNode);

} 


// Find node helper function
TreeNode *findNodeHelperFn(TreeNode *node, int parentData)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->getData() == parentData)
    {
        return node;
    }
    for (int i = 0; i < node->getChildrenCount(); i++)
    {
        TreeNode *searchNode = findNodeHelperFn(node->getChild(i), parentData);
        if (searchNode != nullptr)
        {
            return searchNode;
        }
    }
    return nullptr;
}


// Finds and returns the node with the data otherwise return nullptr.
TreeNode *Tree::findNode(int data)
{
    return findNodeHelperFn(root, data);
} 


// Find Parent Helper Function
TreeNode *findParentHelperFunction(TreeNode *node, int data)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    for (int i = 0; i < node->getChildrenCount(); i++)
    {
        if (node->getChild(i)->getData() == data)
        {
            return node;
        }
    }
    for (int i = 0; i < node->getChildrenCount(); i++)
    {
        TreeNode *parent = findParentHelperFunction(node->getChild(i), data);
        if (parent != nullptr)
        {
            return parent;
        }
    }
    return nullptr;
}

// Find Parent Function
TreeNode *Tree::findParent(int data)
{

    return findParentHelperFunction(root, data);
}

// Returns the degree (the number of children) of the node containing the given data.
int Tree::getDegree(int data)
{
    TreeNode *node = findNode(data);
    return (node->getChildrenCount());
} 

// Pre Order Helper Function
void helperFunctionPreOrder(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    cout << node->getData() << endl;
    for (int i = 0; i < node->getChildrenCount(); i++)
    {
        helperFunctionPreOrder(node->getChild(i));
    }
}

// Prints the tree nodes' data using pre-order traversal (Root, Left, Right).
void Tree::print_pre0rder()
{
    helperFunctionPreOrder(root);
} 



