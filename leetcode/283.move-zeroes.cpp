/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
        map <int,int> M;
        int k = 0;
        for (int i = 0; i < nums.size(); ++i)
            M[i] = nums[i];
        for (auto m : M) {
            if (m.second)
                nums[k++] = m.second;
        }
        for (int j = k; j < nums.size(); ++j)
            nums[j] = 0;
        */
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i])
                swap(nums[i], nums[j++]);
        }
    }
};
// @lc code=end

