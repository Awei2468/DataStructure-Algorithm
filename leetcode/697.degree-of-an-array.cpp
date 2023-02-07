/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 */

// @lc code=start
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map <int,pair<int,int>> M;
        int most = -1, ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (!M.count(nums[i]))
                M[nums[i]] = make_pair(i,1);
            int cnt = ++M[nums[i]].second;
            if (cnt > most) {
                most = cnt;
                ans = i - M[nums[i]].first + 1;
            }
            else if (cnt == most) {
                ans = min(ans, i - M[nums[i]].first + 1);
            }
        }
        return ans;
    }
};
// @lc code=end

