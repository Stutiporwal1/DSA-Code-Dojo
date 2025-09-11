#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int miceHole(vector<int>& mices, vector<int>& holes) {
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());

        int maxTime = 0;
        for(int i = 0; i < mices.size(); i++) {
            maxTime = max(maxTime, abs(mices[i] - holes[i]));
        }
        return maxTime;
    }
};

int main() {
    vector<int> mices = {4, -4, 2};
    vector<int> holes = {4, 0, 5};
    
    Solution s;
    cout << "Brute Force: " << s.bruteForce(mices, holes) << endl; // 4
    cout << "Optimal: " << s.miceHole(mices, holes) << endl;       // 4
    return 0;
}

