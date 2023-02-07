/*
 * @lc app=leetcode id=1848 lang=cpp
 *
 * [1848] Minimum Distance to the Target Element
 */

// @lc code=start
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target)
                ans = abs(i-start) < ans ? abs(i-start) : ans;
        }
        return ans;
    }
};
// @lc code=end

