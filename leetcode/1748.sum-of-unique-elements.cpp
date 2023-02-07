/*
 * @lc app=leetcode id=1748 lang=cpp
 *
 * [1748] Sum of Unique Elements
 */

// @lc code=start
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int res = 0;
        int hash[101] = {0};
        for (int &num : nums) {
            hash[num]++;
            if (hash[num] == 1)
                res += num;
            else if (hash[num] == 2)
                res -= num;
        }
        return res;
    }
};
// @lc code=end

