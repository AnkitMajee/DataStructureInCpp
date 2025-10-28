#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int data)
{
    if (root == nullptr)
        return new Node(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

Node *findLCA(Node *root, int n1, int n2)
{
    while (root != nullptr)
    {
        if (root->data > n1 && root->data > n2)
            root = root->left;
        else if (root->data < n1 && root->data < n2)
            root = root->right;
        else
            return root;
    }
    return nullptr;
}

int main()
{
    Node *root = nullptr;
    int n, data, n1, n2;

    cout << "Enter number of nodes in the BST: ";
    cin >> n;
    cout << "Enter node values:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> data;
        root = insert(root, data);
    }

    cout << "Enter two node values to find their LCA: ";
    cin >> n1 >> n2;
    Node *lca = findLCA(root, n1, n2);

    if (lca != nullptr)
        cout << "LCA of " << n1 << " and " << n2 << ": " << lca->data << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}