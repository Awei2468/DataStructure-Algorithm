/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), r, l;
        vector<int> hash(n + 1, 0);
        for (int &num : nums) {
            hash[num]++;
        }
        for (int i = 0; i < n + 1; ++i) {
            if (hash[i] == 2) r = i;
            if (!hash[i]) l = i;
        }
        return {r,l};
    }
};
// @lc code=end

