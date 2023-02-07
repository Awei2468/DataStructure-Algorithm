/*
 * @lc app=leetcode id=1436 lang=cpp
 *
 * [1436] Destination City
 */

// @lc code=start
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string> ump;
        for (auto &path : paths) {
            ump[path[0]] = path[1];
        }
        string s = ump.begin()->second;
        while (ump.count(s)) {
            s = ump[s];
        }
        return s;
    }
};
// @lc code=end

