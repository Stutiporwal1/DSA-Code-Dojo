/* Longest Increasing Subsequence problem using dynamic programming
 Time Complexity: O(n^2)
 Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxLength = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        return maxLength;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Longest Increasing Subsequence length: " << sol.lengthOfLIS(nums1) << endl; 

    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    cout << "Longest Increasing Subsequence length: " << sol.lengthOfLIS(nums2) << endl; 

    vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
    cout << "Longest Increasing Subsequence length: " << sol.lengthOfLIS(nums3) << endl; 
    
    return 0;
}
