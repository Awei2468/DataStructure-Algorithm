/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution {
private:
    int nums[38];
public:
    Solution() {
        nums[0] = 0;
        nums[1] = 1;
        nums[2] = 1;
        for (int i = 3; i < 38; ++i)
            nums[i] = nums[i-1] + nums[i-2] + nums[i-3];
    }
    int tribonacci(int n) {
        return nums[n];
    }
};
// @lc code=end

