//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void helper(int ind, vector<int> &arr, int target, vector<int> &temp,
                vector<vector<int>> &ans){
        // base case
        if(target==0){
            ans.push_back(temp);
            return;
        }

        // recursive case
        for(int i=ind; i<arr.size(); ++i){
            if(i>ind and arr[i]==arr[i-1])  continue;
            if(arr[i]>target)               break;
            temp.push_back(arr[i]);
            helper(i+1, arr, target-arr[i], temp, ans);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int target)
    {
        //code here
        sort(arr.begin(), arr.end());
        vector<int> temp;
        vector<vector<int>> ans;
        helper(0, arr, target, temp, ans);
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends