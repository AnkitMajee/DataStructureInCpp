#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Insert a node into the BST
Node *insert(Node *root, int data)
{
    if (root == nullptr)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Inorder traversal (Left, Root, Right)
void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Function to find the in-order successor
Node *findSuccessor(Node *root, Node *node)
{
    Node *successor = nullptr;
    while (root)
    {
        if (node->data < root->data)
        {
            successor = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return successor;
}

// Function to find the in-order predecessor
Node *findPredecessor(Node *root, Node *node)
{
    Node *predecessor = nullptr;
    while (root)
    {
        if (node->data > root->data)
        {
            predecessor = root;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return predecessor;
}

int main()
{
    Node *root = nullptr;
    int choice, data, key;

    while (true)
    {
        cout << "\nBinary Search Tree Operations:\n";
        cout << "1. Insert\n2. Inorder Traversal\n3. Find Successor\n4. Find Predecessor\n5. Exit\n";
        cout << "Enter your choice: ";
        
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert: ";
            cin >> data;
            root = insert(root, data);
            break;
        case 2:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;
        case 3:
            cout << "Enter data to find its successor: ";
            cin >> key;
            {
                Node temp{key, nullptr, nullptr}; // Temporary node with given key
                Node *successor = findSuccessor(root, &temp);
                if (successor)
                    cout << "Successor of " << key << " is " << successor->data << endl;
                else
                    cout << "Successor does not exist.\n";
            }
            break;
        case 4:
            cout << "Enter data to find its predecessor: ";
            cin >> key;
            {
                Node temp{key, nullptr, nullptr}; // Temporary node with given key
                Node *predecessor = findPredecessor(root, &temp);
                if (predecessor)
                    cout << "Predecessor of " << key << " is " << predecessor->data << endl;
                else
                    cout << "Predecessor does not exist.\n";
            }
            break;
        case 5:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}