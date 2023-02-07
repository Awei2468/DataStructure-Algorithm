/*
 * @lc app=leetcode id=628 lang=cpp
 *
 * [628] Maximum Product of Three Numbers
 */

// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() == 3) return nums[0]*nums[1]*nums[2];
        sort(nums.begin(), nums.end());
        int len = nums.size(), ans;

        if (nums[0] * nums[1] * nums[len-1] > nums[len-1]*nums[len-2]*nums[len-3])
            ans = nums[0]*nums[1]*nums[len-1];
        else
            ans = nums[len-1]*nums[len-2]*nums[len-3];
            
        return ans;  
    }
};
// @lc code=end

