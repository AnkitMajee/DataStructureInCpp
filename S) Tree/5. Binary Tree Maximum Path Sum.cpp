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

int maxSum(TreeNode* root, int& ans) {
    /* This function return the Branch Sum......
    So if the node is NULL then it won't have a branch....so the branch sum will be 0.
    */
    //Base Case
    if(root == NULL){
        return 0;
    }
    
    //Recursive Case 
    //BS = Branch Sum
    int leftBS = root->val + maxSum( root->left , ans );
    int rightBS = root->val + maxSum( root->right , ans );
    
    ans = max({
                ans,            //we may have found the maximum ans already
                root->val,      //may be the current root val is the maximum sum possible
                leftBS,         //may be the answer contain root->val + left branch value
                rightBS,        //may be the answer contain root->val + right branch value
                leftBS + rightBS - root->val   // may be ans conatin left branch + right branch + root->val
                                               // Since the root val is added twice from leftBS and rightBS so we are sunstracting it.
            });
    
    //Return the max branch Sum
    return max({ leftBS , rightBS , root->val });
}

int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    maxSum(root, ans);
    return ans;
}