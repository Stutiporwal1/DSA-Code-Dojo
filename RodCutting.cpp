/* Rod Cutting problem using a dynamic programming approach.
Time Complexity: O(n^2)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int cutRod(const vector<int>& price, int n) {
        // dp[i] stores the maximum value for a rod of length i
        vector<int> dp(n + 1, 0);

        // Iterate through all possible rod lengths from 1 to n
        for (int i = 1; i <= n; ++i) {
            int max_val = 0;
            // For each length i, consider all possible first cuts j
            for (int j = 1; j <= i; ++j) {
                // The price array is 0-indexed, so price[j-1] is for length j
                max_val = max(max_val, price[j-1] + dp[i - j]);
            }
            dp[i] = max_val;
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    
    // The price array where price[i] is the price for a rod of length i+1
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;
    cout << "For a rod of length " << n << " and prices: ";
    for (int p : price) {
        cout << p << " ";
    }
    cout << endl;
    int result = sol.cutRod(price, n);
    cout << "Maximum obtainable value: " << result << endl;
    return 0;
}
