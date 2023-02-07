/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        /*
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int j = i + 1;
            while (j % nums.size() != i) {
                if (nums[j % nums.size()] > nums[i]) {
                    res.push_back(nums[j % nums.size()]);
                    break;
                }
                ++j;
            }
            if (j % nums.size() == i)
                res.push_back(-1);
        }
        return res;
        */
        int n = nums.size();
        vector < int > res(n, - 1 );
        stack < int > st;
        for ( int i = 0 ; i < 2 * n; ++ i) {
            int num = nums[i % n];
            while (!st.empty() && nums[st.top() ] < num) {
                res[st.top()] = num; st.pop();
            }
            if (i < n) st.push(i);
        }
        return res;
    }
};
// @lc code=end

