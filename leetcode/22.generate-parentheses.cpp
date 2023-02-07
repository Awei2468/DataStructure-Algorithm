/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        Helper(res, "", n, 0);
        return res;
    }
    void Helper(vector<string> &ans, string s, int i, int j) {
        if (!i && !j) {
            ans.push_back(s);
            return;
        }
        if (i > 0)
            Helper(ans, s+"(",  i-1, j+1);
        if (j > 0)
            Helper(ans, s+")",  i, j-1);
    }
};
// @lc code=end

