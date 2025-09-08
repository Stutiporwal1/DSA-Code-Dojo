//
// C++ Solution
//
// Solves the Dijkstra's Algorithm problem using a priority queue.
//
// Time Complexity: O(E log V)
// Space Complexity: O(V + E)
//

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max();

// Structure to represent an edge in the graph
struct Edge {
    int to;
    int weight;
};

class Solution {
public:
    std::vector<int> dijkstra(int V, const std::vector<std::vector<Edge>>& adj, int start) {
        // dist[i] will hold the shortest distance from start to vertex i
        std::vector<int> dist(V, INF);

        // Priority queue stores pairs of {distance, vertex}
        // It's a min-heap by default in C++
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

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

// --- Example Usage ---
int main() {
    Solution sol;
    
    int V = 6;
    std::vector<std::vector<Edge>> adj(V);

    // Graph representation (adjacency list)
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[1].push_back({3, 1});
    adj[2].push_back({1, 2});
    adj[2].push_back({4, 5});
    adj[3].push_back({4, 3});
    adj[4].push_back({5, 1});
    
    int source_vertex = 0;
    std::vector<int> distances = sol.dijkstra(V, adj, source_vertex);

    std::cout << "Shortest distances from source vertex " << source_vertex << ":" << std::endl;
    for (int i = 0; i < V; ++i) {
        std::cout << "To vertex " << i << ": " << (distances[i] == INF ? "INF" : std::to_string(distances[i])) << std::endl;
    }

    return 0;
}
