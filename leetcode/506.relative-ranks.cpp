/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */

// @lc code=start
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> res(score.size(), "");
        map <int, int, greater<int>> M;
        int cnt = 0;
        for (int i = 0; i < score.size(); ++i) {
            M[score[i]] = i;
        }
        for (auto &m : M) {
            ++cnt;
            if (cnt == 1)
                res[m.second] = "Gold Medal";
            else if (cnt == 2)
                res[m.second] = "Silver Medal";
            else if (cnt == 3)
                res[m.second] = "Bronze Medal";
            else
                res[m.second] = to_string(cnt);
        }
        return res;
    }
};
// @lc code=end

