/*
 * @lc app=leetcode id=1752 lang=cpp
 *
 * [1752] Check if Array Is Sorted and Rotated
 */

// @lc code=start
class Solution {
public:
    bool check(vector<int>& nums) {
        if (nums.size() == 1) return true;
        vector<int> tmp = nums;
        bool chk = true;
        int idx = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < nums.size()-1 && nums[i] > nums[i+1] && chk) {
                chk = false;
                idx = i+1;
            }
            tmp.push_back(nums[i]);
        }
        if (chk) return chk;
        chk = true;
        for (int i = idx; i < idx + nums.size() - 1; ++i) {
            if (tmp[i] > tmp[i+1]) {
                chk = false;
                break;
            }
        }
        return chk;
    }
};
// @lc code=end

