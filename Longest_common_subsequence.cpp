/* Longest Common Subsequence problem using dynamic programming.
 Time Complexity: O(m * n)
 Space Complexity: O(m * n)
 m: length of text1, n: length of text2 */


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                   
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[m][n];
    }
};

int main() {
    Solution sol;
    
    string text1_1 = "abcde";
    string text2_1 = "ace";
    cout << "LCS of \"" << text1_1 << "\" and \"" << text2_1 << "\": " << sol.longestCommonSubsequence(text1_1, text2_1) << endl; 
 
    string text1_2 = "abc";
    string text2_2 = "abc";
    cout << "LCS of \"" << text1_2 << "\" and \"" << text2_2 << "\": " << sol.longestCommonSubsequence(text1_2, text2_2) << endl; 

    string text1_3 = "abc";
    string text2_3 = "def";
    cout << "LCS of \"" << text1_3 << "\" and \"" << text2_3 << "\": " << sol.longestCommonSubsequence(text1_3, text2_3) << endl; 
    
    return 0;
}