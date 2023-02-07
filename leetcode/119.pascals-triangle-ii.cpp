/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for (int i = 0; i <= rowIndex; ++i) {
            vector<int> temp;
            for (int j = 0; j <= i; ++j) {
                if (i == j || j == 0) {
                    temp.push_back(1);
                }
                else {
                    temp.push_back(ans[j-1] + ans[j]);
                }
            }
            ans = temp;
        }
        return ans;
    }
};
// @lc code=end

