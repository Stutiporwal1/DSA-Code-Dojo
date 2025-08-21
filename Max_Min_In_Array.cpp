
/* Find the maximum and minimum elements in an array.

Time Complexity: O(n) - We iterate through the array once.
Space Complexity: O(1) - We use a constant amount of extra space. */


#include <iostream>
#include <vector>
#include <limits> 

struct MinMaxPair {
    int min_val;
    int max_val;
};

MinMaxPair findMinMax(const vector<int>& arr) {
   
    if (arr.empty()) {
        return {numeric_limits<int>::max(), numeric_limits<int>::min()};
    }
    
    MinMaxPair result = {arr[0], arr[0]};
    for (size_t i = 1; i < arr.size(); ++i) {
        
        if (arr[i] < result.min_val) {
            result.min_val = arr[i];
        }
        else if (arr[i] > result.max_val) {
            result.max_val = arr[i];
        }
    }
    return result;
}
int main() {
    vector<int> example_array = {3, 5, 2, 8, 1, 9, 4, 7, 6};
    MinMaxPair result = findMinMax(example_array);
    cout << "The minimum element is: " << result.min_val << endl;
    cout << "The maximum element is: " << result.max_val << endl;
    
    return 0;

}
