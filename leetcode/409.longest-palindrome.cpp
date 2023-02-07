/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        if (s.size() == 1) return 1;
        int res = 0;
        bool chk = false;
        unordered_map <char,int> M;
        for (char ch : s) ++M[ch];
        for (auto m : M) {
            if (m.second >= 2) {
                if (m.second == s.size()) return s.size();
                res += (m.second - m.second % 2);
                if (m.second % 2) m.second = 1;
            }
            if (m.second == 1)
                chk = true;
        }
        return chk ? res + 1 : res;
    }
};
// @lc code=end

