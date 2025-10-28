#include <iostream>
#include <queue>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{
    // base case;
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    { // right part me insert karna h
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        // left part me insert karna h
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // purana level complete traverse ho chika hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some chilenodes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node *root)
{
    // base case
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    // base case
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    // base case
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node *minVal(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node *maxVal(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node *deleteFromBST(Node *root, int val)
{
    // base case
    if (root == NULL)
    {
        return root;
    }
    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete (root);
            return NULL;
        }
        // 1 child

        // left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        // left part me jao
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else
    {
        // right part me jao
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

int main()
{
    Node *root = NULL;
    // input
    //  50 20 70 10 30 90 110 -1
    cout << "Enter data to create BST" << endl;
    takeInput(root);
    cout << "Printing the BST" << endl;
    LevelOrderTraversal(root);
    cout << "Printing inorder traversal output " << endl;
    inorder(root);
    cout << endl;
    cout << "Printing preorder traversal output " << endl;
    preorder(root);
    cout << endl;
    cout << "Printing postorder traversal output " << endl;
    postorder(root);
    cout << endl;
    cout << "Min value is " << minVal(root)->data << endl;
    cout << "Max value is " << maxVal(root)->data << endl;

    // Delete
    root = deleteFromBST(root, 50);
    cout << "After deleting the Node " << endl;
    cout << "Printing the BST" << endl;
    LevelOrderTraversal(root);
    cout << "Printing inorder traversal output " << endl;
    inorder(root);
    cout << endl;
    cout << "Printing preorder traversal output " << endl;
    preorder(root);
    cout << endl;
    cout << "Printing postorder traversal output " << endl;
    postorder(root);
    cout << endl;
    cout << "Min value is " << minVal(root)->data << endl;
    cout << "Max value is " << maxVal(root)->data << endl;
    
    return 0;
}