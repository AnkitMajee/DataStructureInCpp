//Saksham Dewan
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max=0, m=accounts.size(), n=accounts[0].size();
        vector<int> wealth;
        for(int i=0;i<m;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=accounts[i][j];
            }
            if(sum>max) max=sum;
        }
        return max;
    }
};
