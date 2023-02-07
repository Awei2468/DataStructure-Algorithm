/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
 */

// @lc code=start
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int hash[101] = {0};
        int res = 0;
        for (int num : nums)
            hash[num]++;
        for (int i = 1; i < 101; ++i) {
            if (hash[i] > 1) {
                res += (hash[i] * (hash[i] - 1) >> 1); 
            }
        }
        return res;
    }
};
// @lc code=end

