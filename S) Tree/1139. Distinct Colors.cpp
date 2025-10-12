/*
 * Description: 
    You have a rooted tree with n nodes (node 1 is the root).
    Each node is assigned a color.
    For each node, compute how many distinct colors appear in its subtree (that node + all its descendants).
    You want to output an array (or list) where answer[i] = number of distinct colors in the subtree of i.
    Example:
      Input:
        5
        2 3 2 2 1
        1 2
        1 3
        3 4
        3 5
      Output:
        3 1 2 1 1
    Constraints:
        1 <= n <= 2*10^5
        1 <= color[i] <= 10^9
        1 <= u, v <= n
        The given edges form a tree.
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define pb push_back

struct BIT {
        vector<int> bit;
        int n;
        BIT(int n) : n(n + 1), bit(n + 1) {}
        int sum(int r) {
                r++;
                int ret = 0;
                while (r > 0) {
                        ret += bit[r];
                        r -= r & -r;
                }
                return ret;
        }

        void update(int idx, int v) {
                idx++;
                while (idx < n) {
                        bit[idx] += v;
                        idx += idx & -idx;
                }
        }
};

const int MAXN = 2e5 + 1;

/*
 * tour = Euler Tour
 * color = color of each node
 * answer = answer for each node
 * lend = left endpoint of each node (as explained in editorial)
 */
int tour[MAXN], color[MAXN], answer[MAXN], lend[MAXN];

vector<int> adj[MAXN];
int idx = 0;

void dfs(int u, int par = 0) {
        lend[u] = idx;
        for (int n : adj[u]) {
                if (n == par) continue;
                dfs(n, u);
        }
        tour[idx] = u;
        idx++;
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int N, u, v;
        cin >> N;
        for (int i = 1; i <= N; i++) { cin >> color[i]; }
        for (int i = 0; i < N - 1; i++) {
                cin >> u >> v;
                adj[u].pb(v);
                adj[v].pb(u);
        }
        dfs(1);
        BIT bit(N);

        // This map stores the rightmost occurrence of each color
        map<int, int> last;
        for (int i = 0; i < N; i++) {//i is the path of dfs
        //tour[i] is the current node at this step of the path
                // If we ever considered the color of tour[i]
                if (last.count(color[tour[i]])) {
                 // The last time the color of tour[i] appeared, we make that 0 again
                        bit.update(last[color[tour[i]]], -1);
                }
                // We change the last occurrence of the color of tour[i]
                last[color[tour[i]]] = i;
                // We reflect that change in our BIT
                bit.update(i, 1);
                /*
                 * The answer for tour[i]'s node is simply
                 * the sum of 1s in its contiguous subinterval in the Euler Tour
                 */
                 //lend show start, i is end of range
                answer[tour[i]] = bit.sum(i) - bit.sum(lend[tour[i]] - 1);
        }
        for (int i = 1; i <= N; i++) { cout << answer[i] << " "; }
}