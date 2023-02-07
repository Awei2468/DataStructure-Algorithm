/*
 * @lc app=leetcode id=1822 lang=cpp
 *
 * [1822] Sign of the Product of an Array
 */

// @lc code=start
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int zero = 0, neg = 0;
        for (int &num : nums) {
            if (!num) zero++;
            else if (num < 0) neg++;
        }
        return zero ? 0 : ((neg & 1) ? -1 : 1);
    }
};
// @lc code=end

