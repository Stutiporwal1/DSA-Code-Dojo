/* Reverse Bits */

#include <iostream>
#include <cstdint> // Required for uint32_t
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed_n = 0;
        int bits_count = 32;

        while (bits_count--) {
            reversed_n <<= 1; // Left shift the result
            reversed_n |= (n & 1); // Add the last bit of n to the result
            n >>= 1; // Right shift n
        }

        return reversed_n;
    }
};

int main() {
    Solution sol;
    
    uint32_t n1 = 0b00000010100101000001111010011100;
    cout << "Original: " << n1 << endl;
    uint32_t reversed1 = sol.reverseBits(n1);
    cout << "Reversed: " << reversed1 << endl;

    uint32_t n2 = 43261596; 
    cout << "Original: " << n2 << endl;
    uint32_t reversed2 = sol.reverseBits(n2);
    cout << "Reversed: " << reversed2 << endl;
    
    return 0;

}
