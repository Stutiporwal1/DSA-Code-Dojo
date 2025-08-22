// Finds the container with the most water using a two-pointer approach.

// Time Complexity: O(n)
// Space Complexity: O(1)


#include <iostream>
#include <vector>

using namespace std;


// This function finds the maximum amount of water that can be contained.
int maxArea(const vector<int>& height) {
    // Initialize pointers at the beginning and end of the array.
    int left = 0;
    int right = height.size() - 1;
    
    // Variable to store the maximum area found so far.
    int max_area = 0;

    // Continue the process until the pointers meet.
    while (left < right) {
        // Calculate the current area.
        int current_area = min(height[left], height[right]) * (right - left);
        
        // Update the maximum area if the current area is larger.
        max_area = max(max_area, current_area);
        
        // Move the pointer that points to the shorter line inward.
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return max_area;
}

// Helper function to print the vector.
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}


int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    
    cout << "Input Array: ";
    printVector(height);
    
    int result = maxArea(height);
    
    cout << "The maximum area of water is: " << result << endl;
    
    return 0;
}