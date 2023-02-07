/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
        map<int , int> M;
        int max = INT_MIN, res;
        for (int i = 0; i < nums.size(); ++i) {
            M[nums[i]]++;
            if (M[nums[i]] >= max) {
                max = M[nums[i]];
                res = nums[i];
            }
        }
        return res;
        */
        int res, count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (!count) {
                res = nums[i];
                ++count;
            }
            else
                (nums[i] == res) ? ++count : --count;
        }
        return res;
    }
};
// @lc code=end

