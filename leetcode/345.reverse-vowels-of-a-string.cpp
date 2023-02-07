/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        stack<char> S;
        queue<int> Q;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                S.push(s[i]);
                Q.push(i);
            }
        }
        while (!S.empty()) {
            s[Q.front()] = S.top();
            S.pop();
            Q.pop();
        }
        return s;
    }
};
// @lc code=end

