/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map <int,int> M;
        for (int i = 0; i < nums.size(); ++i) {
            if (!M[nums[i]])
                M[nums[i]] = i+1;
            else
                return true;
        }
        return false;
    }
};
// @lc code=end

