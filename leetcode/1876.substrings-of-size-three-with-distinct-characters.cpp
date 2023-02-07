/*
 * @lc app=leetcode id=1876 lang=cpp
 *
 * [1876] Substrings of Size Three with Distinct Characters
 */

// @lc code=start
class Solution {
public:
    int countGoodSubstrings(string s) {
        if (s.size() <= 2) return 0;
        int cnt = 0;
        for (int i = 0; i <= s.size()-3; ++i) {
            if (s[i] != s[i+1] && s[i+1] != s[i+2] && s[i] != s[i+2])
                ++cnt;
        }
        return cnt;
    }
};
// @lc code=end

