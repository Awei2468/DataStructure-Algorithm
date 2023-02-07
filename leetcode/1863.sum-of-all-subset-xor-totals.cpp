/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */

// @lc code=start
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        DFS(nums, 0, 0);
        return res;
    }
    void DFS(vector<int>& nums, int i, int val) {
        if (i == nums.size()) {
            res += val;
            return;
        }
        DFS(nums, i+1, val);
        DFS(nums, i+1, val ^ nums[i]);
    }
private:
    int res = 0;
};
// @lc code=end

