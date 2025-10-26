// Kahn's algorithm for topological sort

// Given an adjacency list for a Directed Acyclic Graph (DAG) where adj[u] contains a list of all vertices v such that there exists a
// directed edge u -> v. Return topological sort for the given graph.

// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v,
// vertex u comes before v in the ordering.
// Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then
// the output will be 1 else 0.

// Intuition
// This is a standard graph algorithm that is used to find the topological order of the graph
// This helps us see dependencies between nodes and is useful for many problems

// It works by maintaining a vector that contains the indegrees of all the nodes
// Now if a node has 0 indegree, then that means it doesnt have any dependencies and so we can just write that directly to the answer
// So we remove that node and then for each of that node's neighbors, we reduce their indegree by 1

// This goes on untill we have elements in the queue to process
// Elements are added to the queue when indegree is 0
// If we have a cycle, then there will come a time when the queue will be empty but not all nodes have been processed, in this case, we can not
// return the topological sort of the graph

// Solution

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution
{
public:
	vector<int> topo(int V, vector<vector<int>> adj)
	{

		vector<int> indegree(V, 0);

		// calculate the indegree for all the vertices

		for (int i = 0; i < V; i++)
		{
			for (auto value : adj[i])
			{

				indegree[value]++;
			}
		}

		queue<int> q;

		for (int i = 0; i < V; i++)
		{
			if (indegree[i] == 0)
			{
				q.push(i);
			}
		}
		vector<int> res;

		while (!q.empty())
		{
			int curr = q.front();
			res.push_back(curr);
			q.pop();

			for (auto value : adj[curr])
			{
				indegree[value]--;
				if (indegree[value] == 0)
				{
					q.push(value);
				}
			}
		}

		if (res.size() == V)
		{
			return res;
		}
		return {};
	}
};

int main()
{

	int n = 6;
	vector<vector<int>> adj = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};

	Solution s;

	// call the topological sort function
	vector<int> result = s.topo(n, adj);

	if (result.empty())
	{
		cout << "There is a cycle in the graph, topological sorting not possible." << endl;
	}
	else
	{
		cout << " Result : ";
		for (int i : result)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}