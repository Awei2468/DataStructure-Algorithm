/*
 * @lc app=leetcode id=1854 lang=cpp
 *
 * [1854] Maximum Population Year
 */

// @lc code=start
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int most = -1, minYear = INT_MAX;
        map <int,int> M;
        for (int i = 0; i < logs.size(); ++i) {
            if (M.count(logs[i][0])) continue;
            int birth = logs[i][0];
            for (int j = 0; j < logs.size(); ++j) {
                if (birth >= logs[j][0] && birth <= logs[j][1]-1)
                    M[birth]++;
            }
            if (M[birth] > most) {
                most = M[birth];
                minYear = birth;
            }
            else if (M[birth] == most && birth < minYear) {
                minYear = birth;
            }
        }
        return minYear;
    }
};
// @lc code=end

