/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */

// @lc code=start
class Solution {
public:
    bool rotateString(string s, string goal) {
        /*
        if (!s.size() && !goal.size()) return true;
        if ((!s.size() && goal.size()) || (s.size() && !goal.size()) || (s.size() != goal.size())) return false;
        int cnt = 0, j = 0;
        string tmp = s;
        tmp += s;
        for (int i = 0; i < tmp.size(); ++i) {
            if (tmp[i] == goal[j]) {
                ++cnt;
                ++j;
            }
            else {
                i -= cnt;
                cnt = 0;
                j = 0;
            }
            if (cnt == goal.size()) return true;
        }
        return false;
        */
        int n = s.size(), ng = goal.size();
        if (n != ng) return false;
        s += s;
        /*
        for (int i = 0; i < n; ++i) {
            if (s.substr(i, ng) == goal)
                return true;
        }
        return false;
        */
        return (s.find(goal) > 1000) ? false : true; 
    }
};
// @lc code=end

