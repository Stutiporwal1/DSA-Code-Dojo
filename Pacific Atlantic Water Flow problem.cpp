//
// C++ Solution
//
// Solves the Pacific Atlantic Water Flow problem using Depth First Search (DFS).
//
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
//

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
private:
    int m, n;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // DFS helper function to traverse from an ocean
    void dfs(const vector<vector<int>>& heights, vector<vector<bool>>& reachable, int r, int c) {
        if (reachable[r][c]) {
            return;
        }

        reachable[r][c] = true;

        for (const auto& dir : directions) {
            int new_r = r + dir[0];
            int new_c = c + dir[1];

            if (new_r >= 0 && new_r < m && new_c >= 0 && new_c < n) {
                // Water flows "backwards" from a lower or equal cell to a higher one
                if (heights[new_r][new_c] >= heights[r][c]) {
                    dfs(heights, reachable, new_r, new_c);
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        if (m == 0) {
            return {};
        }
        n = heights[0].size();

        vector<vector<bool>> pacific_reachable(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic_reachable(m, vector<bool>(n, false));
        vector<vector<int>> result;

        // Perform DFS from all cells on the Pacific border
        for (int i = 0; i < m; ++i) {
            dfs(heights, pacific_reachable, i, 0); // Left edge
        }
        for (int j = 0; j < n; ++j) {
            dfs(heights, pacific_reachable, 0, j); // Top edge
        }

        // Perform DFS from all cells on the Atlantic border
        for (int i = 0; i < m; ++i) {
            dfs(heights, atlantic_reachable, i, n - 1); // Right edge
        }
        for (int j = 0; j < n; ++j) {
            dfs(heights, atlantic_reachable, m - 1, j); // Bottom edge
        }

        // Find cells that can reach both oceans
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific_reachable[i][j] && atlantic_reachable[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};

// --- Example Usage ---
int main() {
    Solution sol;
    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };
    
    cout << "Finding cells that can flow to both Pacific and Atlantic oceans." << endl;
    vector<vector<int>> result = sol.pacificAtlantic(heights);

    cout << "Result coordinates: [";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "[" << result[i][0] << ", " << result[i][1] << "]";
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
