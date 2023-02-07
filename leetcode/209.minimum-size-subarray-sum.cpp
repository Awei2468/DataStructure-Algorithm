/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, sum = 0, size = __INT_MAX__;
        for (int end = 0; end < nums.size(); ++end) {
            sum += nums[end];
            while (sum >= target) {
                size = (size > end-start+1) ? end-start+1 : size;
                sum -= nums[start++];
            }
        }
        return (size == __INT_MAX__) ? 0 : size;
    }
};
// @lc code=end

