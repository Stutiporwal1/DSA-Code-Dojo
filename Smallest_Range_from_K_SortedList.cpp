/* coding ninjas
 Smallest Range from K Sorted List
 https://www.codingninjas.com/codestudio/problems/smallest-range-from
*/

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

class compare {
public:
    bool operator()(tuple<int,int,int> a, tuple<int,int,int> b) {
        return get<0>(a) > get<0>(b); // min-heap based on element value
    }
};

pair<int,int> kSorted(vector<vector<int>>& kSortedArray) {
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, compare> minHeap;
    int maxElement = INT_MIN; 
    int rangeStart = 0, rangeEnd = 0; 
    int minRange = INT_MAX; 

    // Initialize heap with first element of each list
    for (int i = 0; i < kSortedArray.size(); i++) {
        if (!kSortedArray[i].empty()) {
            minHeap.push({kSortedArray[i][0], i, 0}); // {value, listIndex, elementIndex}
            maxElement = max(maxElement, kSortedArray[i][0]);
        }
    }

    while (minHeap.size() == kSortedArray.size()) {
        auto [minElement, listIndex, eleIndex] = minHeap.top();
        minHeap.pop();

        // Update best range
        if (maxElement - minElement < minRange) {
            minRange = maxElement - minElement;
            rangeStart = minElement;
            rangeEnd = maxElement;
        }

        // Move to next element in the same list
        if (eleIndex + 1 < kSortedArray[listIndex].size()) {
            int nextVal = kSortedArray[listIndex][eleIndex + 1];
            minHeap.push({nextVal, listIndex, eleIndex + 1});
            maxElement = max(maxElement, nextVal);
        }
    }

    return {rangeStart, rangeEnd};
}

int main() {
    int k;
    cout << "Enter the number of sorted lists: ";
    cin >> k;
    vector<vector<int>> kSortedArray(k);

    for (int i = 0; i < k; i++) {
        int n;
        cout << "Enter the number of elements in list " << i + 1 << ": ";
        cin >> n;
        kSortedArray[i].resize(n);
        cout << "Enter the elements of list " << i + 1 << ": ";
        for (int j = 0; j < n; j++) {
            cin >> kSortedArray[i][j];
        }
    }

    auto result = kSorted(kSortedArray);
    cout << "The smallest range is: [" << result.first << ", " << result.second << "]" << endl;
    return 0;
}

