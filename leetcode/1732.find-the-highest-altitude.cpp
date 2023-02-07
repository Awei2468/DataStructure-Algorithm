/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
 */

// @lc code=start
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int Max = INT_MIN;
        gain.insert(gain.begin(), 0);
        for (int i = 1; i < gain.size(); ++i) {
            gain[i] += gain[i-1];
            if (gain[i] > Max)
                Max = gain[i];
        }
        return Max > 0 ? Max : 0;
    }
};
// @lc code=end

