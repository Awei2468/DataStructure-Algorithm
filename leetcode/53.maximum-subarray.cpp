/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int t = 0, res = INT_MIN;
        for (int num : nums) {
            t = (t + num > num) ? t + num : num;
            res = (t > res) ? t : res;
        }
        return res;
    }
};
// @lc code=end

