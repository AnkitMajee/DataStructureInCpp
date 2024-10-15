/*
https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1
Given a binary tree with **n** nodes. Find the zig-zag level order traversal of the binary tree.In zig zag traversal starting from the first level go from **left to right** for odd-numbered levels and **right to left** for even-numbered levels.

**Example 1:**

```
Input:
        1
      /   \
     2    3
    / \    /   \
   4   5 6   7
Output:
1 3 2 4 5 6 7
Explanation:
For level 1 going left to right, we get traversal as {1}.
For level 2 going right to left, we get traversal as {3,2}.
For level 3 going left to right, we get traversal as {4,5,6,7}.
Merging all this traversals in single array we get {1,3,2,4,5,6,7}

```

**Example 2:**

```
Input:
           7
        /     \
       9      7
     /  \      /
    8   8   6
   /  \
  10  9
Output:
7 7 9 8 8 6 9 10
Explanation:
For level 1 going left to right, we get traversal as {7}.
For level 2 going right to left, we get traversal as {7,9}.
For level 3 going left to right, we get traversal as {8,8,6}.
For level 4 going right to left, we get traversal as {9,10}.
Merging all this traversals in single array we get {7,7,9,8,8,6,9,10}.
```

**Your Task:**You don't need to read input or print anything. Your task is to complete the function **zigZagTraversal()** which takes the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the zig-zag level-order traversal of the tree.

**Expected Time Complexity:** O(n).**Expected Auxiliary Space:** O(n).

**Constraints:** 1 <= n <= 105
*/
//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
  int data;
  Node *left;
  Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
  Node *temp = new Node;
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
  // Corner Case
  if (str.length() == 0 || str[0] == 'N')
    return NULL;

  // Creating vector of strings from input
  // string after spliting by space
  vector<string> ip;

  istringstream iss(str);
  for (string str; iss >> str;)
    ip.push_back(str);

  // Create the root of the tree
  Node *root = newNode(stoi(ip[0]));

  // Push the root to the queue
  queue<Node *> queue;
  queue.push(root);

  // Starting from the second element
  int i = 1;
  while (!queue.empty() && i < ip.size())
  {

    // Get and remove the front of the queue
    Node *currNode = queue.front();
    queue.pop();

    // Get the current node's value from the string
    string currVal = ip[i];

    // If the left child is not null
    if (currVal != "N")
    {

      // Create the left child for the current node
      currNode->left = newNode(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->left);
    }

    // For the right child
    i++;
    if (i >= ip.size())
      break;
    currVal = ip[i];

    // If the right child is not null
    if (currVal != "N")
    {

      // Create the right child for the current node
      currNode->right = newNode(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->right);
    }
    i++;
  }

  return root;
}

// } Driver Code Ends
// User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
  // Function to store the zig zag order traversal of tree in a list.
  vector<int> zigZagTraversal(Node *root)
  {
    // Code here
  }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main()
{

  int t;
  scanf("%d ", &t);
  while (t--)
  {
    string s, ch;
    getline(cin, s);

    Node *root = buildTree(s);

    vector<int> ans;
    Solution ob;
    ans = ob.zigZagTraversal(root);

    for (int i = 0; i < ans.size(); i++)
      cout << ans[i] << " ";

    cout << endl;
  }
  return 0;
}

// } Driver Code Ends