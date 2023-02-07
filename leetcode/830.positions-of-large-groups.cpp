/*
 * @lc app=leetcode id=830 lang=cpp
 *
 * [830] Positions of Large Groups
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        int len = s.size(), acc = 1;
        s.push_back('.');
        for (int i = 0; i < len; ++i) {
            if (s[i] == s[i+1])
                ++acc;
            else {
                if (acc >= 3)
                    res.push_back({i - acc + 1, i});
                acc = 1;
            }
        }
        return res;
    }
};
// @lc code=end

