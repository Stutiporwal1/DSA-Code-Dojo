/* Minimum Platforms problem using a greedy approach with sorting.
 Time Complexity: O(n log n)
 Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinPlatforms(vector<int>& arr, vector<int>& dep) {
        // Sort both the arrival and departure arrays
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int n = arr.size();
        int platforms_needed = 0;
        int max_platforms = 0;
        int i = 0; // Pointer for arrival times
        int j = 0; // Pointer for departure times

        // Traverse through both arrays
        while (i < n && j < n) {
            // If a train arrives, a platform is occupied
            if (arr[i] <= dep[j]) {
                platforms_needed++;
                i++;
            }
            // If a train departs, a platform is freed
            else {
                platforms_needed--;
                j++;
            }
            
            // Update the maximum number of platforms needed
            if (platforms_needed > max_platforms) {
                max_platforms = platforms_needed;
            }
        }

        return max_platforms;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep1 = {910, 1200, 1120, 1130, 1900, 2000};
    cout << "Minimum platforms needed: " << sol.findMinPlatforms(arr1, dep1) << endl; 

    vector<int> arr2 = {500, 510, 520, 530};
    vector<int> dep2 = {515, 525, 535, 545};
    cout << "Minimum platforms needed: " << sol.findMinPlatforms(arr2, dep2) << endl; 

    return 0;
}
