/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int tmp = 0;
        for (int num : nums) {
            tmp += num;
        }
        return (((1 + nums.size()) * nums.size()) >> 1) - tmp;
    }
};
// @lc code=end

