/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map <string, vector<int>> M;
        vector<string> copys = strs;
        for (int i = 0; i < strs.size(); ++i) {
            sort(copys[i].begin(), copys[i].end());
            M[copys[i]].push_back(i);
        }
        for (auto m : M) {
            vector<string> tmp;
            for (int idx : m.second)
                tmp.push_back(strs[idx]);
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end

