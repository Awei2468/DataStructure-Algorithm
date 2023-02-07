/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m];
        for (int i = 0; i < m; ++i)
            dp[i] = 1;
        for (int i = 0; i < n-1; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j > 0) {
                    dp[j] += dp[j-1];
                }
            }
        }
        return dp[m-1];
    }
};
// @lc code=end

