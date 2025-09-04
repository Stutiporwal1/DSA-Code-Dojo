/* Fractional Knapsack problem using a greedy approach.
 Time Complexity: O(n log n)
 Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
};


bool compareItems(const Item& a, const Item& b) {
    double r1 = static_cast<double>(a.value) / a.weight;
    double r2 = static_cast<double>(b.value) / b.weight;
    return r1 > r2;
}

class Solution {
public:
    double fractionalKnapsack(int capacity, vector<Item>& items) {
        // 1. Sort items by their value-to-weight ratio in descending order
        sort(items.begin(), items.end(), compareItems);

        double totalValue = 0.0;
        int currentWeight = 0;

        // 2. Iterate through sorted items and fill the knapsack
        for (const auto& item : items) {
            // If the whole item fits, take it
            if (currentWeight + item.weight <= capacity) {
                currentWeight += item.weight;
                totalValue += item.value;
            } else {
                // Otherwise, take a fraction of the item
                int remainingCapacity = capacity - currentWeight;
                totalValue += static_cast<double>(item.value) *
                              (static_cast<double>(remainingCapacity) / item.weight);
                break; // Knapsack is full
            }
        }
        return totalValue;
    }
};

int main() {
    Solution sol;
    
    int knapsackCapacity = 50;
    vector<Item> items = {
        {60, 10}, {100, 20}, {120, 30}
    };

    double maxValue = sol.fractionalKnapsack(knapsackCapacity, items);
    cout << "Maximum value in knapsack: " << maxValue << endl; 
    
    return 0;
}