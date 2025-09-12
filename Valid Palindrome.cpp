/* Valid Palindrome problem using a two-pointer approach
 Time Complexity: O(n)
 Space Complexity: O(n)
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string filteredString;
        for (char c : s) {
            if (isalnum(c)) {
                filteredString += tolower(c);
            }
        }
        
        int left = 0;
        int right = filteredString.length() - 1;

        while (left < right) {
            if (filteredString[left] != filteredString[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};

int main() {
    Solution sol;
    string s1 = "A man, a plan, a canal: Panama";
    cout << "\"" << s1 << "\" is a palindrome: " << (sol.isPalindrome(s1) ? "true" : "false") << endl;

    string s2 = "race a car";
    cout << "\"" << s2 << "\" is a palindrome: " << (sol.isPalindrome(s2) ? "true" : "false") << endl;

    string s3 = " ";
    cout << "\"" << s3 << "\" is a palindrome: " << (sol.isPalindrome(s3) ? "true" : "false") << endl;

    return 0;
}
