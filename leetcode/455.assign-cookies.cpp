/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int g_index = 0, s_index = 0;
        while (g_index < g.size() && s_index < s.size()) {
            if (g[g_index] <= s[s_index]) ++g_index;
            ++s_index;
        }
        return g_index;
    }
};
// @lc code=end

