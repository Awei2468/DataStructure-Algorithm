/*
 * @lc app=leetcode id=1886 lang=cpp
 *
 * [1886] Determine Whether Matrix Can Be Obtained By Rotation
 */

// @lc code=start
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (mat == target) return true;  //origin
        vector<vector<int>> tmp1 = mat, tmp2 = mat, tmp3 = mat;
        int len = mat.size();
        for (int i = 0; i < len; ++i) {  
            for (int j = 0; j < len; ++j) {
                tmp1[i][j] = mat[j][len-1-i];  //right top
                tmp2[i][j] = mat[len-1-i][len-1-j];  //right down
                tmp3[i][j] = mat[len-1-j][i];  // left down
            }              
        }
        if (tmp1 == target || tmp2 == target || tmp3 == target) return true;
        else return false;
    }
};
// @lc code=end

