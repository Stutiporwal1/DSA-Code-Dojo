/* Hamming Distance problem using bitwise operations.
Time Complexity: O(1)
Space Complexity: O(1)
*/

#include <iostream>
#include <cstdint>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int xor_result = x ^ y;
        int count = 0;
        
        // Count the number of set bits in the XOR result
        while (xor_result > 0) {
            
            // xor_result &= (xor_result - 1) removes the least significant set bit
            xor_result &= (xor_result - 1);
            count++;
        }
        return count;
    }
};

int main() {
    
    Solution sol;
    int x1 = 1, y1 = 4;
    cout << "Hamming distance between " << x1 << " and " << y1 << " is: " << sol.hammingDistance(x1, y1) << endl; 
    
    int x2 = 3, y2 = 1;
    cout << "Hamming distance between " << x2 << " and " << y2 << " is: " << sol.hammingDistance(x2, y2) << endl; 

    int x3 = 25, y3 = 30; // 25 = 11001, 30 = 11110. XOR is 00111 = 7. Count is 3.
    cout << "Hamming distance between " << x3 << " and " << y3 << " is: " << sol.hammingDistance(x3, y3) << endl; 
    return 0;
}
