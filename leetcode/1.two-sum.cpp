/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> M;
        //vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (M.count(target - nums[i])) {
                return {M[target - nums[i]], i};
            }
            else
                M[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

