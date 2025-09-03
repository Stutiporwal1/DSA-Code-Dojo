/* Edit Distance problem using dynamic programming.
 Time Complexity: O(m * n)
 Space Complexity: O(m * n)
 m: length of word1, n: length of word2
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int insert_cost = dp[i][j - 1];
                    int delete_cost = dp[i - 1][j];
                    int replace_cost = dp[i - 1][j - 1];
                    dp[i][j] = 1 + min({insert_cost, delete_cost, replace_cost});
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution sol;
    
    string word1_1 = "horse";
    string word2_1 = "ros";
    cout << "Minimum operations to convert \"" << word1_1 << "\" to \"" << word2_1 << "\": " << sol.minDistance(word1_1, word2_1) << endl; 

    string word1_2 = "intention";
    string word2_2 = "execution";
    cout << "Minimum operations to convert \"" << word1_2 << "\" to \"" << word2_2 << "\": " << sol.minDistance(word1_2, word2_2) << endl; 

    string word1_3 = "kitten";
    string word2_3 = "sitting";
    cout << "Minimum operations to convert \"" << word1_3 << "\" to \"" << word2_3 << "\": " << sol.minDistance(word1_3, word2_3) << endl; 
    
    return 0;
}