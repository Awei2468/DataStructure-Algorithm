/*
 * @lc app=leetcode id=1572 lang=cpp
 *
 * [1572] Matrix Diagonal Sum
 */

// @lc code=start
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += mat[i][i];
            sum += mat[i][n-1-i];
        }
        return (n & 1) ? sum - mat[n/2][n/2] : sum;
    }
};
// @lc code=end

