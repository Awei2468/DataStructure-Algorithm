/*
 * @lc app=leetcode id=925 lang=cpp
 *
 * [925] Long Pressed Name
 */

// @lc code=start
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        /*
        vector<pair<char,int>> tmp1, tmp2;
        tmp1.push_back({'$',1});
        tmp2.push_back({'$',1});
        for (char &c : name) {
            if (tmp1.back().first != c) tmp1.push_back({c,1});
            else tmp1.back().second++;
        }
        for (char &c : typed) {
            if (tmp2.back().first != c) tmp2.push_back({c,1});
            else tmp2.back().second++;
        }
        if (tmp1.size() != tmp2.size()) return false;
        int len = tmp1.size();
        for (int i = 1; i < len; ++i) {
            if (tmp1[i].second > tmp2[i].second || tmp1[i].first != tmp2[i].first)
                return false;
        }
        return true;
        */
        int n = typed.size(), m = name.size(), j = 0;
        for (int i = 0; i < n; ++i) {
            if (j < m && name[j] == typed[i]) {
                ++j;
            }
            else if (!i || typed[i-1] != typed[i])
                return false;
        }
        return j == m;
    }
};
// @lc code=end

