/* Dijkstra's Algorithm problem using a priority queue
 Time Complexity: O(E log V)
 Space Complexity: O(V + E)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>max();
struct Edge {
    int to;
    int weight;
};

class Solution {
public:
    vector<int> dijkstra(int V, const vector<vector<Edge>>& adj, int start) {
        // dist[i] will hold the shortest distance from start to vertex i
        vector<int> dist(V, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[start] = 0;
        pq.push({0, start});
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            // If we have found a shorter path, skip this
            if (d > dist[u]) {
                continue;
            }
            // Iterate through all neighbors of u
            for (const auto& edge : adj[u]) {
                int v = edge.to;
                int weight = edge.weight;

                // If a shorter path to v is found through u
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};
int main() {
    Solution sol;
    int V = 6;
    vector<vector<Edge>> adj(V);

    // (adjacency list)
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[1].push_back({3, 1});
    adj[2].push_back({1, 2});
    adj[2].push_back({4, 5});
    adj[3].push_back({4, 3});
    adj[4].push_back({5, 1});
    
    int source_vertex = 0;
    vector<int> distances = sol.dijkstra(V, adj, source_vertex);
    cout << "Shortest distances from source vertex " << source_vertex << ":" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "To vertex " << i << ": " << (distances[i] == INF ? "INF" : to_string(distances[i])) << endl;
    }
    return 0;
}
