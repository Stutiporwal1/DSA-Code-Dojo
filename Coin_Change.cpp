// time complexity
O(amount × number_of_coins)
// Coin Change
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        if (dp[amount] > amount) {
            return -1;
        } else {
            return dp[amount];
        }
    }
};

int main() {
    Solution sol;
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Fewest coins for amount " << amount1 << ": " << sol.coinChange(coins1, amount1) << endl;

    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Fewest coins for amount " << amount2 << ": " << sol.coinChange(coins2, amount2) << endl;

    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Fewest coins for amount " << amount3 << ": " << sol.coinChange(coins3, amount3) << endl; 

    return 0;
}


