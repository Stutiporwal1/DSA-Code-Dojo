/* Solves the Binary Search problem.
Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

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

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    int target2 = 2;

    cout << "Target " << target1 << " is at index: " << sol.search(nums, target1) << endl; 
    cout << "Target " << target2 << " is at index: " << sol.search(nums, target2) << endl; 

    vector<int> nums2 = {5};
    int target3 = 5;
    cout << "Target " << target3 << " is at index: " << sol.search(nums2, target3) << endl; 

    vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target4 = 7;
    cout << "Target " << target4 << " is at index: " << sol.search(nums3, target4) << endl; 
    return 0;
}
