/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map <int,int> M;
        for (int i = 0; i < nums.size(); ++i) {
            if (!M[nums[i]])
                M[nums[i]] = i+1;
            else {
                if (abs(i+1-M[nums[i]]) <= k)
                    return true;
                M[nums[i]] = i+1;
            }
        }
        return false;
    }
};
// @lc code=end

