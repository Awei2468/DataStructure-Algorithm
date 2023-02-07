/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int dir = 0, up = 0, down = n-1, left = 0, right = n-1, t = 1;
        while (t <= n*n) {
            switch (dir % 4) {
                case 0: //right
                    for (int j = left; j <= right; ++j)
                        res[up][j] = t++;
                    ++up;
                    break;
                case 1: //down
                    for (int j = up; j <= down; ++j)
                        res[j][right] = t++;
                    --right;
                    break;
                case 2: //left
                    for (int j = right; j >= left; --j)
                        res[down][j] = t++;
                    --down;
                    break;
                default: //up
                    for (int j = down; j >= up; --j)
                        res[j][left] = t++;
                    ++left;
                    break;
            }
            ++dir;
        }
        return res;
    }
};
// @lc code=end

