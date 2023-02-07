/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), SmalltoBig);

        int res = 0;
        int size = points.size();
        int i = size-1;

        while (i >= 0) {
            int arrow = points[i][0];
            while (i >= 1 && arrow <= points[i-1][1])
                --i;
            ++res;
            --i;
        }
        return res;
    }

    static bool SmalltoBig(vector<int>& x, vector<int> &y) {
        return x[0] == y[0] ? x[1] < y[1] : x[0] < y[0];
    }
};
// @lc code=end

