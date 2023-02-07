/*
 * @lc app=leetcode id=1800 lang=cpp
 *
 * [1800] Maximum Ascending Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        /*
        int sum = nums[0], len = nums.size(), Max = INT_MIN;
        nums.push_back(-1);
        for (int i = 0; i < len; ++i) {
            if (sum > Max) Max = sum;
            if (nums[i] < nums[i+1])
                sum += nums[i+1];
            else
                sum = nums[i+1];
        }
        return Max;
        */
        int sum = nums[0], res = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i-1] >= nums[i]) {
                res = max(res, sum);
                sum = 0;
            }
            sum += nums[i];
        }
        return max(sum, res);
    }
};
// @lc code=end

