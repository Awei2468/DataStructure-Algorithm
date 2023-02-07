/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> P(numRows);
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i)
                    P[i].push_back(1);
                else
                    P[i].push_back(P[i-1][j-1] + P[i-1][j]);
            }
        }
        return P;
    }
};
// @lc code=end

