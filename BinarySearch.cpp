//
// C++ Solution
//
// Solves the Binary Search problem.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)
//

#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};

// --- Example Usage ---
int main() {
    Solution sol;
    std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    int target2 = 2;

    std::cout << "Target " << target1 << " is at index: " << sol.search(nums, target1) << std::endl; // Expected: 4
    std::cout << "Target " << target2 << " is at index: " << sol.search(nums, target2) << std::endl; // Expected: -1

    std::vector<int> nums2 = {5};
    int target3 = 5;
    std::cout << "Target " << target3 << " is at index: " << sol.search(nums2, target3) << std::endl; // Expected: 0

    std::vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target4 = 7;
    std::cout << "Target " << target4 << " is at index: " << sol.search(nums3, target4) << std::endl; // Expected: 6

    return 0;
}
