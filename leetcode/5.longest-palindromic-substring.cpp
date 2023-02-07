/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int len = 1, left = 0, n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
            for (int j = 0; j < i; ++j) {
                if (s[i] == s[j] && (i - j  < 2 || dp[j+1][i-1]))
                    dp[j][i] = true;
                else
                    dp[j][i] = false;

                if (dp[j][i] && (i - j + 1 > len)) {
                    len = i - j + 1;
                    left = j;
                }
            }
        }
        return s.substr(left, len);
    }
};
// @lc code=end

