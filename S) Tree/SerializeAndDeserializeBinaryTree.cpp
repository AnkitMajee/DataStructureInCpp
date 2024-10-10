// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
// Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

// Example 1:
// Input: root = [1,2,3,null,null,4,5]
// Output: [1,2,3,null,null,4,5]
// Example 2:
// Input: root = []
// Output: []

class Codec {
public:
    
    void buildString(TreeNode* root, string &res)
    {
        if(root == NULL)
        {   res += "null,";
            return;
        }
        
        res += to_string(root->val) + ",";
        buildString(root->left, res);
        buildString(root->right, res);
    }
    
    string serialize(TreeNode* root) 
    { 
        string res = "";
        buildString(root, res);
        return res;
    }
    
    TreeNode* buildTree(queue<string> &q) 
    {
        string s = q.front();
        q.pop();
        
        if(s == "null")
            return NULL;
        
        TreeNode* root = new TreeNode(stoi(s));
        root->left = buildTree(q);
        root->right = buildTree(q);
        return root;
    }
    
    TreeNode* deserialize(string data) 
    {
        string s = "";
        queue <string> q;
        
        for(char c: data) 
        {
            if(c == ',') 
            {
                q.push(s);
                s = "";
            }
            else
                s += c;
        }
        
        return buildTree(q);
    }
};
