/*
 * @lc app=leetcode id=1480 lang=cpp
 *
 * [1480] Running Sum of 1d Array
 */

// @lc code=start
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            res.push_back(sum);
        }
        return res;
    }
};
// @lc code=end

