/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (!trust.size() && n == 1) return n;
        else if (!trust.size()) return -1;
        unordered_map <int,int> M;
        int ans = -1;
        for (int i = 0; i < trust.size(); ++i) {
            M[trust[i][1]]++;
            if (M[trust[i][1]] == n-1) {
                ans = trust[i][1];
                break;
            }
        }
        if (ans == -1) return ans;
        for (int i = 0; i < trust.size(); ++i) {
            if (ans == trust[i][0]) {
                ans = -1;
                break;
            }     
        }
        return ans;   
    }
};
// @lc code=end

