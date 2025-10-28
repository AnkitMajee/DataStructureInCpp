
// vertical traversal of binary tree

// main observation:-nodes whose numbering/indexing is same , are at the same vertical level
// for more than one nodes at the same vertical  level , we put that node first in the answer array whose level is low
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// function to ge the left level depth and right level depth
void find(Node *root, int pos, int &l, int &r)
{
    if (!root)
        return;
    l = min(pos, l);
    r = max(pos, r);
    find(root->left, pos - 1, l, r);
    find(root->right, pos + 1, l, r);
}
// to dot this we can use the level order traversal and
//  we take two 2D arrays negative and positive to collect the values which are at the same vertical level as per the position
vector<int> verticalOrder(Node *root)
{
    if (!root)
        return {};

    vector<int> ans;
    int l = 0, r = 0;

    find(root, 0, l, r); // to ge the maximum depth/level on the both side

    queue<Node *> q;
    queue<int> index;
    q.push(root);
    index.push(0);

    // two  2D arrays
    vector<vector<int>> positive(r + 1);
    vector<vector<int>> negative(abs(l) + 1);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        int pos = index.front();
        index.pop();
        // it means we need to push value into the positive 2D array ,where pos works as outer index
        if (pos >= 0)
            positive[pos].push_back(temp->data);

        else // negative me push
            negative[abs(pos)].push_back(temp->data);

        //  then the regular work of the level order traversal
        if (temp->left)
        {
            q.push(temp->left);
            index.push(pos - 1);
        }
        if (temp->right)
        {
            q.push(temp->right);
            index.push(pos + 1);
        }
    }

    // we need to push the values of the both 2D vector into the 1D vector
    // negative 2D vector push from the last
    //  positive 2D vector push form the start
    for (int i = negative.size() - 1; i > 0; i--)
    { // as in the index zero of the outer loop, there is no value ,as those values are already covered into the positive 2D arrays
        for (int j = 0; j < negative[i].size(); j++)
        {
            ans.push_back(negative[i][j]);
        }
    }
    for (int i = 0; i < positive.size(); i++)
    {
        for (int j = 0; j < positive[i].size(); j++)
        {
            ans.push_back(positive[i][j]);
        }
    }

    return ans;
}

int main()
{
    return 0;
}