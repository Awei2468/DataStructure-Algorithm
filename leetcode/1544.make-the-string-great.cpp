/*
 * @lc app=leetcode id=1544 lang=cpp
 *
 * [1544] Make The String Great
 */

// @lc code=start
class Solution {
public:
    string makeGood(string s) {
        if (s.size() == 1) return s;
        int gap = 'a' - 'A';
        for (int i = 0; i < s.size()-1; ++i) {
            if (s[i] + gap == s[i+1] || s[i] - gap == s[i+1]) {
                s.erase(i, 2);
                i = 0;
            }
        }
        return s;
    }
};
// @lc code=end

