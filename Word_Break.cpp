/* Word Break problem using a dynamic programming approach.
 Time Complexity: O(n^2)
 Space Complexity: O(n + m), where m is the size of the dictionary
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(const string& s, const vector<string>& wordDict) {
        // Use a hash set for efficient O(1) average-time word lookups
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        int n = s.length();
        
        // dp[i] is true if s[0...i-1] can be segmented
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && word_set.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    string s1 = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};
    cout << "For s = \"" << s1 << "\" and dictionary: [\"leet\", \"code\"]" << endl;
    if (sol.wordBreak(s1, wordDict1)) {
        cout << "Output: true" << endl;
    } else {
        cout << "Output: false" << endl;
    }
    cout << "\n";
    
    string s2 = "applepenapple";
    vector<string> wordDict2 = {"apple", "pen"};
    cout << "For s = \"" << s2 << "\" and dictionary: [\"apple\", \"pen\"]" << endl;
    if (sol.wordBreak(s2, wordDict2)) {
        cout << "Output: true" << endl;
    } else {
        cout << "Output: false" << endl;
    }
    cout << "\n";
    
    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << "For s = \"" << s3 << "\" and dictionary: [\"cats\", \"dog\", \"sand\", \"and\", \"cat\"]" << endl;
    if (sol.wordBreak(s3, wordDict3)) {
        cout << "Output: true" << endl;
    } else {
        cout << "Output: false" << endl;
    }
    return 0;
}
