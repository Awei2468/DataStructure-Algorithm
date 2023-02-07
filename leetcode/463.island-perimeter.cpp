/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    if (j == 0 || !grid[i][j-1]) ++res;
                    if (j == grid[0].size()-1 || !grid[i][j+1]) ++res;
                    if (i == 0 || !grid[i-1][j]) ++res;
                    if (i == grid.size()-1 || !grid[i+1][j]) ++res;
                }
            }
        }
        return res;
    }
};
// @lc code=end

