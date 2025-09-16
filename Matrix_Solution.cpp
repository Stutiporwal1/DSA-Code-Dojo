/* Finds the distance of the nearest 0 for each cell in a matrix using multi-source BFS.
 Time Complexity: O(m * n)
 Space Complexity: O(m * n)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        // Initialize the queue with all cells that have a 0
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (mat[r][c] == 0) {
                    result[r][c] = 0;
                    q.push({r, c});
                }
            }
        }

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            int r = current.first;
            int c = current.second;

            for (const auto& dir : directions) {
                int next_r = r + dir.first;
                int next_c = c + dir.second;

                // Check for boundary conditions and if the neighbor is unvisited
                if (next_r >= 0 && next_r < m && next_c >= 0 && next_c < n) {
                    if (result[next_r][next_c] > result[r][c] + 1) {
                        result[next_r][next_c] = result[r][c] + 1;
                        q.push({next_r, next_c});
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };
    
    Solution sol;
    vector<vector<int>> result = sol.updateMatrix(mat);

    cout << "Result Matrix:" << endl;
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
