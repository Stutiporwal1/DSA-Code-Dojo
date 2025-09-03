#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Create a DP array and initialize with a value greater than any possible result.
        // amount + 1 can be used as "infinity" since the max coins would be amount if all coins were 1.
        vector<int> dp(amount + 1, amount + 1);
        
        // Base case: 0 coins are needed to make an amount of 0.
        dp[0] = 0;
        
        // Iterate through all amounts from 1 to the target amount.
        for (int i = 1; i <= amount; ++i) {
            // For each amount, check all coin denominations.
            for (int coin : coins) {
                // If the current amount is greater than or equal to the coin value,
                // we can potentially use this coin.
                if (i >= coin) {
                    // Update dp[i] with the minimum of its current value
                    // or the number of coins to make the remaining amount (dp[i-coin]) + 1 (for the current coin).
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        // If dp[amount] is still "infinity," it means the amount is unreachable.
        if (dp[amount] > amount) {
            return -1;
        } else {
            return dp[amount];
        }
    }
};

// --- Example Usage ---
int main() {
    Solution sol;
    
    // Example 1
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Fewest coins for amount " << amount1 << ": " << sol.coinChange(coins1, amount1) << endl; // Expected: 3

    // Example 2
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Fewest coins for amount " << amount2 << ": " << sol.coinChange(coins2, amount2) << endl; // Expected: -1

    // Example 3
    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Fewest coins for amount " << amount3 << ": " << sol.coinChange(coins3, amount3) << endl; // Expected: 0

    return 0;
}