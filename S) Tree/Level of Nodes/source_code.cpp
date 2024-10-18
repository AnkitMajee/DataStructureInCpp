class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    vector<bool> vis(V+1, false);
	    int level = 0;
	    queue<int> q;
	    q.push(0);
	    vis[q.front()] = true;
	    while(q.size()){
	        ++level;
	        int count = q.size();
	        while(count--){
	            int front = q.front();
	            q.pop();
	            for(auto &i : adj[front]){
	                if(!vis[i]){
	                    vis[i] = true;
	                    if(i == X)  return level;
	                    q.push(i);
	                }
	            }
	        }
	    }
	    return -1;
	}
};