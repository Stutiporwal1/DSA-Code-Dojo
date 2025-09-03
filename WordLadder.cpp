#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        dict.erase(beginWord);

        while (!q.empty()) {
            string current_word = q.front().first;
            int current_distance = q.front().second;
            q.pop();

            if (current_word == endWord) {
                return current_distance;
            }

            for (int i = 0; i < current_word.size(); ++i) {
                char original_char = current_word[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    current_word[i] = c;
                    if (dict.find(current_word) != dict.end()) {
                        q.push({current_word, current_distance + 1});
                        dict.erase(current_word);
                    }
                }
                current_word[i] = original_char; 
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;
    
    string beginWord1 = "hit";
    string endWord1 = "cog";
    vector<string> wordList1 = {"hot", "dot", "dog", "lot", "log", "cog"};
    int result1 = sol.ladderLength(beginWord1, endWord1, wordList1);
    cout << "Shortest ladder length (Example 1): " << result1 << endl; 

    string beginWord2 = "hit";
    string endWord2 = "cog";
    vector<string> wordList2 = {"hot", "dot", "dog", "lot", "log"};
    int result2 = sol.ladderLength(beginWord2, endWord2, wordList2);
    cout << "Shortest ladder length (Example 2): " << result2 << endl; 

    return 0;
}