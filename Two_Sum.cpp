#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Problem: Two Sum
Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.

Example:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]  (because nums[0] + nums[1] == 9)
*/

// Brute Force Approach 
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class SolutionBrute {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

// Optimized Approach 
// Using Hash Map (unordered_map)
// Time Complexity: O(n)
// Space Complexity: O(n)
class SolutionOptimized {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; // number -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // check if complement already seen
            auto it = numMap.find(complement);
            if (it != numMap.end()) {
                return {it->second, i};
            }

            // store current number
            numMap[nums[i]] = i;
        }

        return {};
    }
};

 
int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    SolutionBrute brute;
    SolutionOptimized opt;

    // Run Brute Force
    vector<int> res1 = brute.twoSum(nums, target);
    cout << "Brute Force Result: ";
    if (!res1.empty()) cout << "[" << res1[0] << ", " << res1[1] << "]\n";

    // Run Optimized
    vector<int> res2 = opt.twoSum(nums, target);
    cout << "Optimized Result: ";
    if (!res2.empty()) cout << "[" << res2[0] << ", " << res2[1] << "]\n";

    return 0;
}


