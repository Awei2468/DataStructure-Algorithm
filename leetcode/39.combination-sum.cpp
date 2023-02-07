/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> tmp;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return res;
    }
    void dfs(vector<int>& candidates, int target, int start) {
        if (target < 0) return;  //not answer
        if (!target) {  //one of answer
            res.push_back(tmp);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            tmp.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i);
            tmp.pop_back();
        }
    }
};
// @lc code=end

