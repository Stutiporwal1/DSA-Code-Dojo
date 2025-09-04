// coding ninjas
// Smallest Range from K Sorted List
// https://www.codingninjas.com/codestudio/problems/smallest-range-from

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class compare {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first; // Min-heap based on the first element
    }
};

int kSorted(vector<vector<int>>& kSortedArray) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> minHeap;
    int maxElement = INT_MIN; // To track the maximum element in the current range
    int rangeStart = 0, rangeEnd = 0; // To store the smallest range
    int minRange = INT_MAX; // To store the minimum range found

    // Initialize the min-heap with the first element of each sorted list
    for (int i = 0; i < kSortedArray.size(); i++) {
        if (!kSortedArray[i].empty()) {
            minHeap.push({kSortedArray[i][0], i});
            maxElement = max(maxElement, kSortedArray[i][0]);
        }
    }

    while (minHeap.size() == kSortedArray.size()) {
        auto [minElement, listIndex] = minHeap.top();
        minHeap.pop();

        // Update the range if it's smaller than the previous minimum range
        if (maxElement - minElement < minRange) {
            minRange = maxElement - minElement;
            rangeStart = minElement;
            rangeEnd = maxElement;
        }

        // Move to the next element in the same list
        if (++listIndex < kSortedArray[listIndex].size()) {
            minHeap.push({kSortedArray[listIndex][listIndex], listIndex});
            maxElement = max(maxElement, kSortedArray[listIndex][listIndex]);
        }
    }

    return minRange;
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

    int result = kSorted(kSortedArray);
    cout << "The smallest range is: " << result << endl;

    return 0;
} 