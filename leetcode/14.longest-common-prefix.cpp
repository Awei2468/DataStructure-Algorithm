/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int match;
        if (!strs.size()) return res;
        for (int i = 0; i < strs[0].length(); ++i) {
            match = 0;
            for (int j = 0; j < strs.size(); ++j) {
                if (strs[0][i] == strs[j][i])
                    match++;
            }
            if (match == strs.size()) {
                res += strs[0][i];
                if (i != res.length()-1) {
                    res.erase(res.length()-1, 1);
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

