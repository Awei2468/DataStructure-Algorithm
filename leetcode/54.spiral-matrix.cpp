/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int dir = 0, L = 0, R = matrix[0].size()-1, U = 0, D = matrix.size()-1;
        while (U <= D && L <= R) {
            if (dir % 4 == 0) {  //right
                for (int j = L; j <= R; ++j)
                    res.push_back(matrix[U][j]);
                ++U;
            }
            else if (dir % 4 == 1) {  //down
                for (int i = U; i <= D; ++i)
                    res.push_back(matrix[i][R]);
                --R;
            }
            else if (dir % 4 == 2) {  //left
                for (int j = R; j >= L; --j)
                    res.push_back(matrix[D][j]);
                --D;
            }
            else {  //up
                for (int i = D; i >= U; --i)
                    res.push_back(matrix[i][L]);
                ++L;
            }
            ++dir;
        }
        return res;
    }
};
// @lc code=end

