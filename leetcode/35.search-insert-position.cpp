/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (target == nums[i])
                return i;
            else if (target > nums[i])
                ++j;
            else
                break;
        }
        return j;
    }
};
// @lc code=end

