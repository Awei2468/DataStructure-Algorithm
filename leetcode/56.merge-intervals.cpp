/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int n = intervals.size(), i = 0, l = intervals[0][0], r = intervals[0][1], rmax = intervals[0][1];
        while (++i < n) {
            if (r < intervals[i][0] && rmax < intervals[i][0]) {
                res.push_back({l, rmax});
                l = intervals[i][0];
                r = intervals[i][1];
                rmax = intervals[i][1];
            }
            if (intervals[i][1] > rmax) rmax = intervals[i][1];
        }
        res.push_back({l, rmax});
        return res;
    }
};
// @lc code=end

