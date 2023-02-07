/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), dp[m][n], Max = INT_MIN;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dp[i][j] = 0;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] - '0') dp[i][0] = 1;
            Max = max(Max, dp[i][0]);
        }
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] - '0') dp[0][j] = 1;
            Max = max(Max, dp[0][j]);
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] - '0')
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                else
                    dp[i][j] = 0;
                Max = max(Max, dp[i][j]); 
            }
        }
        return Max * Max;
    }
};
// @lc code=end

