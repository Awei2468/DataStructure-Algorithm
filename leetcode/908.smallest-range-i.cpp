/*
 * @lc app=leetcode id=908 lang=cpp
 *
 * [908] Smallest Range I
 */

// @lc code=start
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int max = nums[0], min = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > max) max = nums[i];
            if (nums[i] < min) min = nums[i];
        }
        return (max-min > 2*k) ? (max-min-2*k) : 0;
    }
};
// @lc code=end

