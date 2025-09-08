/* Minimum Path Sum in a Grid problem using dynamic programming.
 Time Complexity: O(m * n)
 Space Complexity: O(1) (by modifying the input grid in-place)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        // The value at grid[i][j] will store the minimum path sum to reach that cell
        // Fill the first row
        for (int j = 1; j < n; ++j) {
            grid[0][j] += grid[0][j - 1];
        }
        // Fill the first column
        for (int i = 1; i < m; ++i) {
            grid[i][0] += grid[i - 1][0];
        }
        // Fill the rest of the grid
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid1 = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << "Input Grid: " << endl;
    for (const auto& row : grid1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "Minimum Path Sum: " << sol.minPathSum(grid1) << endl; 
    cout << "\n";
    
    vector<vector<int>> grid2 = {{1, 2}, {1, 1}};
    cout << "Input Grid: " << endl;
    for (const auto& row : grid2) {
        for (int val : row) {
            cout << val << " ";
        }
         cout << endl;
    }
    cout << "Minimum Path Sum: " << sol.minPathSum(grid2) << endl; 
    return 0;
}
