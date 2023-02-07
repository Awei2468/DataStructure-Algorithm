/*
 * @lc app=leetcode id=1403 lang=cpp
 *
 * [1403] Minimum Subsequence in Non-Increasing Order
 */

// @lc code=start
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> res;
        int sum = 0, n = nums.size(), local = 0;
        sort(nums.begin(), nums.end());
        for (int &num : nums) sum += num;
        for (int i = n - 1; i >= 0; --i) {
            res.push_back(nums[i]);
            local += nums[i];
            if (local > sum - local) break; 
        }
        return res;
    }
};
// @lc code=end

