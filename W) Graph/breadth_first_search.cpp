// Breadth First Search

// Given a graph, return the order of traversal of the graph starting from node 0

// Intuition
// This is also called the level order traversal


// Solution

#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
	
    vector<vector<int>> floyd(vector<vector<int>> &adj , int n) {
//        cout<<"?\n";
        // the dist vector initial value is set to INT_MAX
        // after processing, if distance is INT_MAX, that means there is no way from source to that node
        vector<vector<int>> dist(n , vector<int>(n , -1));

        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < n ; j++){
                dist[i][j] = adj[i][j];
            }
        }

        for (int k = 0 ; k < n ; k++){
            for (int i = 0 ; i < n ; i++){
                for (int j = 0 ; j < n ; j++){
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && (dist[i][j] == INT_MAX || dist[i][j] > (dist[i][k] + dist[k][j]))){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

		
		return dist;

    }
};

int main()
{
    Solution sol;
    // adjacency matrix
        vector<vector<int>> adj = {
        {0, 4, 1, INT_MAX, INT_MAX},
        {INT_MAX, 0, INT_MAX, 1, INT_MAX},
        {INT_MAX, 2, 0, 5, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 0, 3},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0}};
    // adj[i][j] is the weight of edge from i to j
    // if its INT_MAX, then the edge does not exist
    
    int n = 5;

    vector<vector<int>> result = sol.floyd(adj , n);
    cout << "Result : "<<endl;
    for (auto val:result){
        for (auto value:val){
        	if (value == INT_MAX){
        		cout<<"INF\t";
        		continue;
			}
            cout<<value<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}