/*
 * @lc app=leetcode id=1646 lang=cpp
 *
 * [1646] Get Maximum in Generated Array
 */

// @lc code=start
class Solution {
private:
    int nums[101], res[101], big;
public:
    Solution() {
        nums[0] = 0;
        res[0] = 0;
        nums[1] = 1;
        res[1] = 1;
        big = 1;
        for (int i = 2; i < 101; ++i) {
            if (i & 1)
                nums[i] = nums[i >> 1] + nums[(i >> 1) + 1];
            else
                nums[i] = nums[i >> 1];
            if (nums[i] > big) {
                res[i] = nums[i];
                big = nums[i];
            }
            else
                res[i] = big;
        }
    }
    int getMaximumGenerated(int n) {
        return res[n];
    }
};
// @lc code=end

