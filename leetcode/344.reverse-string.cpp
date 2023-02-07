/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size() == 1) return;
        for (int i = 0; i <= (s.size() >> 1) - 1; ++i) {
            if (s[i] != s[s.size()-1-i])
                s[i] ^= s[s.size()-1-i] ^= s[i] ^= s[s.size()-1-i];
        }
    }
};
// @lc code=end

