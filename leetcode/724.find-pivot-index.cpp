/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0, sum = 0, res = -1;
        for (int n : nums) sum += n;
        for (int i = 0; i < nums.size(); ++i) {
            if ((left == sum - left - nums[i]) || (i == nums.size()-1 && left == 0)) {
                res = i;
                break;
            }
            else
                left += nums[i];
        }
        return res;
    }
};
// @lc code=end

