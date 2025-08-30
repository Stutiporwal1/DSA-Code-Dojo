/* Detects a cycle in an undirected graph using BFS.
 Time Complexity: O(V + E)
 Space Complexity: O(V)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

class Solution {
private:
    bool detectCycleBFS(int startNode, int V, const vector<list<int>>& adj, vector<bool>& visited, vector<int>& parent) {
        queue<int> q;
        
        visited[startNode] = true;
        parent[startNode] = -1;
        q.push(startNode);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                } else if (v != parent[u]) {
                    // This means a visited node is not the parent, so a cycle exists.
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool hasCycle(int V, const vector<list<int>>& adj) {
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (detectCycleBFS(i, V, adj, visited, parent)) {
                    return true;
                }
            }
        }
        return false;
    }
};

// --- Example Usage ---
int main() {
    Solution sol;
    int V1 = 5;
    vector<list<int>> adj1(V1);
    // Graph 1 (with cycle): 0-1-2-3-1
    adj1[0].push_back(1);
    adj1[1].push_back(0);
    adj1[1].push_back(2);
    adj1[2].push_back(1);
    adj1[2].push_back(3);
    adj1[3].push_back(2);
    adj1[3].push_back(4);
    adj1[4].push_back(3);
    adj1[4].push_back(1);
    adj1[1].push_back(4);

    bool result1 = sol.hasCycle(V1, adj1);
    cout << "Graph 1 has a cycle: " << (result1 ? "true" : "false") << endl; 

    int V2 = 4;
    vector<list<int>> adj2(V2);
    // Graph 2 (no cycle): 0-1, 1-2, 2-3
    adj2[0].push_back(1);
    adj2[1].push_back(0);
    adj2[1].push_back(2);
    adj2[2].push_back(1);
    adj2[2].push_back(3);
    adj2[3].push_back(2);
    
    bool result2 = sol.hasCycle(V2, adj2);
    cout << "Graph 2 has a cycle: " << (result2 ? "true" : "false") << endl; // Expected: false

    return 0;
}