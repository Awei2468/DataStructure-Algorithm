/*
 * @lc app=leetcode id=1816 lang=cpp
 *
 * [1816] Truncate Sentence
 */

// @lc code=start
class Solution {
public:
    string truncateSentence(string s, int k) {
        int n = s.size(), len = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                --k;
                if (!k) break;
            }
            ++len;
        }
        return s.substr(0, len);
    }
};
// @lc code=end

