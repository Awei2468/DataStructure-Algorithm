/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> us;
        for (int num : nums) {
            if (num > 0)
                us.insert(num);
        }
        for (int i = 1; i < INT_MAX; ++i) {
            if (!us.count(i))
                return i;
        }
        return 0;
    }
};
// @lc code=end

