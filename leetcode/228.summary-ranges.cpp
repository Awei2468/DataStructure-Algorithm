/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (!nums.size()) return res;
        int i = 0;
        while (i < nums.size()) {
            int start = i, end;
            while (i + 1 < nums.size() && nums[i+1] == nums[i] + 1)
                ++i;
            end = i;
            if (start != end)
                res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            else
                res.push_back(to_string(nums[start]));
            i++;
        }
        return res;
    }
};
// @lc code=end

