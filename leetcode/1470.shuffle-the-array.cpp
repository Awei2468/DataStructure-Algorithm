/*
 * @lc app=leetcode id=1470 lang=cpp
 *
 * [1470] Shuffle the Array
 */

// @lc code=start
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        int len = nums.size();
        for (int i = 0; i < n; ++i) {
            res.push_back(nums[i]);
            res.push_back(nums[i+n]);
        }
        return res;
    }
};
// @lc code=end

