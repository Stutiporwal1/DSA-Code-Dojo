/* House Robbery problem using dynamic programming.
 Time Complexity: O(n)
 Space Complexity: O(n) (can be optimized to O(1))
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int result1 = robSimple(nums, 0, n - 2);
        
        int result2 = robSimple(nums, 1, n - 1);
        
        return max(result1, result2);
    }
private:
    int robSimple(const vector<int>& nums, int start, int end) {
        if (start > end) return 0;
        if (start == end) return nums[start];
        
        vector<int> dp(end - start + 1, 0);
        dp[0] = nums[start];
        if (end - start > 0) {
            dp[1] = max(nums[start], nums[start + 1]);
        }
        
        for (int i = 2; i <= end - start; ++i) {
            dp[i] = max(dp[i - 1], nums[start + i] + dp[i - 2]);
        }
        
        return dp.back();
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {2, 3, 2};
    cout << "Maximum amount for {2, 3, 2}: " << sol.rob(nums1) << endl; 

    vector<int> nums2 = {1, 2, 3, 1};
    cout << "Maximum amount for {1, 2, 3, 1}: " << sol.rob(nums2) << endl; 

    vector<int> nums3 = {0};
    cout << "Maximum amount for {0}: " << sol.rob(nums3) << endl; 
    
    return 0;

}
