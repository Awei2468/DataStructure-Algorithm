/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*//O(n^2)
        int n = nums.size(), res = 1;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            res = max(res, dp[i]);
        }
        return res;
        */
        int n = nums.size();
        vector<int> res;
        for (int &num : nums) {
            auto iter = lower_bound(res.begin(), res.end(), num);
            if (iter == res.end()) res.push_back(num);
            else *iter = num;
        }
        return res.size();
    }
};
// @lc code=end

