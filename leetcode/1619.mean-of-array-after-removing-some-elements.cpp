/*
 * @lc app=leetcode id=1619 lang=cpp
 *
 * [1619] Mean of Array After Removing Some Elements
 */

// @lc code=start
class Solution {
public:
    double trimMean(vector<int>& arr) {
        int del = arr.size() / 20;
        int sum = 0;
        sort(arr.begin(), arr.end());
        for (int i = del; i < arr.size() - del; ++i)
            sum += arr[i];
        return (double)sum / (arr.size() - 2 * del);
    }
};
// @lc code=end

