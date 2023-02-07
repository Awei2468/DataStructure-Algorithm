/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        /*//2D array
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i && j)
                    dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
                else if (!i && j)
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                else if (i && !j)
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                else
                    dp[i][j] = grid[i][j];
            }
        }
        return dp[m-1][n-1];*/
        //1D array
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i && j)
                    dp[j] = grid[i][j] + min(dp[j-1], dp[j]);
                else if (!i && j)
                    dp[j] = grid[i][j] + dp[j-1];
                else if (i && !j)
                    dp[j] = grid[i][j] + dp[j];
                else
                    dp[j] = grid[i][j];
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

