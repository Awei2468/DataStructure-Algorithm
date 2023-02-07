/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map <int,int> M;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            M[nums[i]]++;
        }
        for (auto m : M) {
            if (m.second == 1)
                res.push_back(m.first);
        }
        return res;
    }
};
// @lc code=end

