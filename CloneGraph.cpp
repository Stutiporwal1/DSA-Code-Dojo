/*Creates a deep copy of a graph using DFS and a hash map.
 Time Complexity: O(V + E)
 Space Complexity: O(V)
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }

        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        Node* clone = new Node(node->val);
        visited[node] = clone;

        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};

// --- Helper functions for testing ---
void printGraph(Node* node, unordered_map<Node*, bool>& visited_print) {
    if (!node || visited_print.find(node) != visited_print.end()) {
        return;
    }

    visited_print[node] = true;
    cout << "Node " << node->val << " neighbors: ";
    for (Node* neighbor : node->neighbors) {
        cout << neighbor->val << " ";
    }
    cout << endl;

    for (Node* neighbor : node->neighbors) {
        printGraph(neighbor, visited_print);
    }
}

int main() {
    // Creating a simple graph: 1 -- 2, 2 -- 3, 3 -- 1
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node3);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node1);
    node3->neighbors.push_back(node2);

    Solution sol;
    Node* cloned_graph = sol.cloneGraph(node1);

    cout << "Original Graph:" << endl;
    unordered_map<Node*, bool> visited_orig;
    printGraph(node1, visited_orig);
    cout << endl;

    cout << "Cloned Graph:" << endl;
    unordered_map<Node*, bool> visited_clone;
    printGraph(cloned_graph, visited_clone);

    // Clean up memory
    delete node1;
    delete node2;
    delete node3;
    

    return 0;
}