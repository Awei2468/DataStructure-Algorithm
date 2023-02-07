/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (!nums.size()) return 0;
        int cnt = 1, Max = INT_MIN;
        set<int> s(nums.begin(), nums.end());
        for (auto iterB = s.begin(), iterF = ++s.begin(); iterB != s.end() && iterF != s.end(); ++iterB, ++iterF) {
            if (*iterF - *iterB == 1)
                ++cnt;
            else {
                if (cnt > Max)
                    Max = cnt;
                cnt = 1;
            }
        }
        return max(Max, cnt);
    }
};
// @lc code=end

