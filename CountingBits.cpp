/* Counting Bits problem using dynamic programming and bit manipulation.

 Time Complexity: O(n)
 Space Complexity: O(n) */


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            // Using the DP relation: dp[i] = dp[i >> 1] + (i % 2)
            // The number of set bits in i is the same as in i/2 (i>>1), plus 1 if i is odd.
            dp[i] = dp[i >> 1] + (i & 1); // (i % 2) is the same as (i & 1)
        }
        return dp;
    }
    vector<int> countBits_v2(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i & (i-1)] + 1;
        }
        return dp;
    }
};

int main() {
    Solution sol;
    
    int n1 = 2;
    vector<int> result1 = sol.countBits(n1); 
    cout << "For n = 2, counts are: ";
    for (int count : result1) {
        cout << count << " ";
    }
    cout << endl;
    
    int n2 = 5;
    vector<int> result2 = sol.countBits(n2); 
    cout << "For n = 5, counts are: ";
    for (int count : result2) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}