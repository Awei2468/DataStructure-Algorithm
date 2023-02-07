/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums, 0, nums.size()-1);
        return res;
    }
    void helper(vector<int> &nums, int i, int n) {
        if (i == n)
            res.push_back(nums);
        else {
            for (int j = i; j <= n; ++j) {
                swap(nums[i], nums[j]);
                helper(nums, i+1, n);
                swap(nums[i], nums[j]);
            }
        }
    }
};
// @lc code=end

