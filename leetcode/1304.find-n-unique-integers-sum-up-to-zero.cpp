/*
 * @lc app=leetcode id=1304 lang=cpp
 *
 * [1304] Find N Unique Integers Sum up to Zero
 */

// @lc code=start
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        int t = n >> 1;
        for (int i = 1; i <= t; ++i) {
            res.push_back(i);
            res.push_back(-i);
        }
        if (n & 1)
            res.push_back(0);
        return res;
    }
};
// @lc code=end

