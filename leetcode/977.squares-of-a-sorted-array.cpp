/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        stack<int> S;
        int i;
        for (i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                S.push(nums[i]*nums[i]);
            }
            else
                break;
        }
        while (!S.empty() && i < nums.size()) { //+-
            int t = nums[i]*nums[i];
            if (t < S.top()) {
                res.push_back(t);
                ++i;
            }
            else if (t == S.top()) {
                res.push_back(t);
                res.push_back(S.top());
                S.pop();
                ++i;
            }
            else {
                res.push_back(S.top());
                S.pop();
            }
        }
        while (!S.empty()) {  //only -
            res.push_back(S.top());
            S.pop();
        }
        while (i < nums.size()) {  // residual +
            int t = nums[i]*nums[i];
            res.push_back(t);
            ++i;
        }
        return res;
    }
};
// @lc code=end

