/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
 */

// @lc code=start
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        stack<int> stk;
        int n = arr.size();
        for (int i = n-1; i >= 0; --i) {
            stk.push(arr[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (stk.top()) {
                arr[i] = stk.top();
                stk.pop();
            }
            else {
                arr[i] = 0;
                if (i+1 < n)
                    arr[i+1] = 0;
                stk.pop();
                i += 1;
            }
        }
    }
};
// @lc code=end

