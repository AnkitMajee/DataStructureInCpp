// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
// Given the root of a binary tree, return the maximum path sum of any non-empty path.
// The path sum of a path is the sum of the node's values in the path.

// Example 1:
// Input: root = [1,2,3]
// Output: 6
// Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

// Example 2:
// Input: root = [-10,9,20,null,null,15,7]
// Output: 42
// Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

// Constraints:
// The number of nodes in the tree is in the range [1, 3 * 104].
// -1000 <= Node.val <= 1000

#include <iostream>
#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxSum(TreeNode *root, int &ans)
{
    if (root == NULL)
        return 0;

    // Recursively find maximum branch sums from left and right
    int leftBS = max(0, maxSum(root->left, ans)); // Ignore negative paths
    int rightBS = max(0, maxSum(root->right, ans));

    // Update the global maximum with the best path passing through the root
    ans = max(ans, root->val + leftBS + rightBS);

    // Return the best branch (root + one side)
    return root->val + max(leftBS, rightBS);
}

int maxPathSum(TreeNode *root)
{
    int ans = INT_MIN;
    maxSum(root, ans);
    return ans;
}