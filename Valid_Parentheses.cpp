//
// C++ Solution
//
// Determines if a string of parentheses is valid using a stack.
//
// Time Complexity: O(n)
// Space Complexity: O(n)
//

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    // An unordered_map to quickly find matching brackets.
    unordered_map<char, char> map = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    
    // The stack to store open brackets.
    stack<char> st;

    // Iterate through the string.
    for (char c : s) {
        // If it's an open bracket, push it onto the stack.
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else { // It's a closing bracket.
            // If the stack is empty or the top doesn't match, return false.
            if (st.empty() || map[c] != st.top()) {
                return false;
            }
            // Otherwise, we have a match, so pop the open bracket.
            st.pop();
        }
    }

    // After the loop, if the stack is empty, all brackets were matched.
    return st.empty();
}

// --- Example Usage ---
int main() {
    string s1 = "()[]{}";
    string s2 = "([{}])";
    string s3 = "(]";
    string s4 = "{[()]}";
    
    cout << s1 << " is valid: " << (isValid(s1) ? "true" : "false") << endl;
    cout << s2 << " is valid: " << (isValid(s2) ? "true" : "false") << endl;
    cout << s3 << " is valid: " << (isValid(s3) ? "true" : "false") << endl;
    cout << s4 << " is valid: " << (isValid(s4) ? "true" : "false") << endl;

    return 0;
}