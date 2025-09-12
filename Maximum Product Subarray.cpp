#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int result = nums[0];
        int max_so_far = nums[0];
        int min_so_far = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            int current_num = nums[i];
            
            // Store the old max_so_far before updating
            int temp_max = max_so_far;

            // Update max_so_far
            max_so_far = max({current_num, current_num * temp_max, current_num * min_so_far});
            
            // Update min_so_far
            min_so_far = min({current_num, current_num * temp_max, current_num * min_so_far});
            
            // Update the overall result
            result = max(result, max_so_far);
        }

        return result;
    }
};

// --- Example Usage ---
int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {2, 3, -2, 4};
    cout << "Maximum product for {2, 3, -2, 4} is: " << sol.maxProduct(nums1) << endl; // Expected output: 6
    
    // Example 2
    vector<int> nums2 = {-2, 0, -1};
    cout << "Maximum product for {-2, 0, -1} is: " << sol.maxProduct(nums2) << endl; // Expected output: 0
    
    // Example 3
    vector<int> nums3 = {-2, -3, -4};
    cout << "Maximum product for {-2, -3, -4} is: " << sol.maxProduct(nums3) << endl; // Expected output: 12
    
    return 0;
}
