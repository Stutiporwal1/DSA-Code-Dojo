// Find the Bridge edge

#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>

using namespace std;

vector<pair<int,int>> ans;
int timer=0;
void dfs(int node, int parent, unordered_map<int,list<int>>&adj, vector<int>&vis, vector<int>&tin, vector<int>&low) {
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;

    for(auto it : adj[node]) {
        if(it == parent) continue; // If the adjacent node is the parent, skip it
        if(!vis[it]) {
            dfs(it, node, adj, vis, tin, low);
            low[node] = min(low[node], low[it]);

            // Check if the edge is a bridge
            if(low[it] > tin[node]) {
                ans.push_back({node, it});
            }
        } else {
            // Back edge case
            low[node] = min(low[node], tin[it]);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n, 0);
    vector<int> tin(n, -1);
    vector<int> low(n, -1);

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, -1, adj, vis, tin, low);
        }
    }

    cout << "Bridges in the graph are:\n";
    for(auto it : ans) {
        cout << it.first << " - " << it.second << "\n";
    }

    return 0;
}
