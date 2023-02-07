/*
 * @lc app=leetcode id=495 lang=cpp
 *
 * [495] Teemo Attacking
 */

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = duration;
        for (int i = 1; i < timeSeries.size(); ++i) {
            int target = timeSeries[i-1] + duration - 1;
            if (timeSeries[i] < target)
                res += (timeSeries[i] + duration - 1 - target);
            else if (timeSeries[i] > target)
                res += duration;
            else
                res += (duration - 1);
        }
        return res;
    }
};
// @lc code=end

