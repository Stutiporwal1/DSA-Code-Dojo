#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }

        int prev2 = 1; 
        int prev1 = 2; 
        int current = 0;

        for (int i = 3; i <= n; ++i) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return current;
    }
};


int main() {
    Solution sol;
    int n1 = 2;
    cout << "Ways to climb " << n1 << " steps: " << sol.climbStairs(n1) << endl; 
    
    int n2 = 3;
    cout << "Ways to climb " << n2 << " steps: " << sol.climbStairs(n2) << endl; 

    int n3 = 4;
    cout << "Ways to climb " << n3 << " steps: " << sol.climbStairs(n3) << endl; 

    int n4 = 5;
    cout << "Ways to climb " << n4 << " steps: " << sol.climbStairs(n4) << endl; 

    return 0;
}