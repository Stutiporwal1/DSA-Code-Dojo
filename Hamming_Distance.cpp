//
// C++ Solution
//
// Solves the Hamming Distance problem using bitwise operations.
//
// Time Complexity: O(1)
// Space Complexity: O(1)
//

#include <iostream>
#include <cstdint>

class Solution {
public:
    int hammingDistance(int x, int y) {
        int xor_result = x ^ y;
        int count = 0;
        
        // Count the number of set bits in the XOR result
        while (xor_result > 0) {
            // A common trick to count set bits:
            // xor_result &= (xor_result - 1) removes the least significant set bit
            xor_result &= (xor_result - 1);
            count++;
        }
        
        return count;
    }
};

// --- Example Usage ---
int main() {
    Solution sol;
    
    int x1 = 1, y1 = 4;
    std::cout << "Hamming distance between " << x1 << " and " << y1 << " is: " << sol.hammingDistance(x1, y1) << std::endl; // Expected: 2
    
    int x2 = 3, y2 = 1;
    std::cout << "Hamming distance between " << x2 << " and " << y2 << " is: " << sol.hammingDistance(x2, y2) << std::endl; // Expected: 1

    int x3 = 25, y3 = 30; // 25 = 11001, 30 = 11110. XOR is 00111 = 7. Count is 3.
    std::cout << "Hamming distance between " << x3 << " and " << y3 << " is: " << sol.hammingDistance(x3, y3) << std::endl; // Expected: 3

    return 0;
}
