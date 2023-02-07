/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public: 
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n-2 && nums[i] <= 0; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int tar = 0 - nums[i], j = i+1, k = n-1;
            while (j < k) {
                if (nums[j] + nums[k] == tar) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j+1]) ++j;
                    while (j < k && nums[k] == nums[k-1]) --k;
                    ++j;
                    --k;
                }
                else if (nums[j] + nums[k] < tar)
                    ++j;
                else
                    --k;
            }
        }
        return res;
    }
};
// @lc code=end

