/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, max = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] & 1)
                ++cnt;
            else
                cnt = 0;
            if (cnt > max) max = cnt;
        }
        return max;
    }
};
// @lc code=end

