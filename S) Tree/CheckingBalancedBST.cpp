#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert a node in a BST
TreeNode *insertNode(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        return new TreeNode(val);
    }
    if (val < root->val)
    {
        root->left = insertNode(root->left, val);
    }
    else
    {
        root->right = insertNode(root->right, val);
    }
    return root;
}

// Helper function to check if a tree is balanced and return its height
int checkHeight(TreeNode *node)
{
    if (node == nullptr)
        return 0;

    int leftHeight = checkHeight(node->left);
    if (leftHeight == -1)
        return -1;

    int rightHeight = checkHeight(node->right);
    if (rightHeight == -1)
        return -1;

    if (std::abs(leftHeight - rightHeight) > 1)
        return -1;

    return std::max(leftHeight, rightHeight) + 1;
}

// Function to check if the tree is balanced
bool isBalanced(TreeNode *root)
{
    return checkHeight(root) != -1;
}

// Function to display the BST (In-order Traversal)
void displayTree(TreeNode *root)
{
    if (root == nullptr)
        return;
    displayTree(root->left);
    cout << root->val << " ";
    displayTree(root->right);
}

int main()
{
    TreeNode *root = nullptr;
    int choice, value;

    cout << "Binary Search Tree - Check if Height-Balanced\n";
    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert Node\n";
        cout << "2. Display Tree (In-order Traversal)\n";
        cout << "3. Check if Balanced\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insertNode(root, value);
            cout << "Node inserted.\n";
            break;
        case 2:
            cout << "BST In-order Traversal: ";
            displayTree(root);
            cout << endl;
            break;
        case 3:
            if (isBalanced(root))
            {
                cout << "The tree is balanced.\n";
            }
            else
            {
                cout << "The tree is not balanced.\n";
            }
            break;
        case 4:
            cout << "Exiting.\n";
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
}