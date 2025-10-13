#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int,int>>> adj(V); // {neighbor, weight}
    for(int i=0;i<E;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    key[0] = 0; // start from node 0

    for(int count=0; count<V-1; count++){
        int u = -1;
        for(int i=0;i<V;i++)
            if(!inMST[i] && (u==-1 || key[i]<key[u]))
                u=i;

        inMST[u] = true;

        for(auto [v,w]: adj[u])
            if(!inMST[v] && w < key[v]){
                key[v] = w;
                parent[v] = u;
            }
    }

    cout << "Edges in MST:\n";
    for(int i=1;i<V;i++)
        cout << parent[i] << " - " << i << " \n";

    return 0;
}
