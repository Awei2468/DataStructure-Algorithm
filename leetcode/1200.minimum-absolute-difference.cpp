/*
 * @lc app=leetcode id=1200 lang=cpp
 *
 * [1200] Minimum Absolute Difference
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        int Min = INT_MAX;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size()-1; ++i) {
            if (arr[i+1] - arr[i] < Min)
                Min = arr[i+1] - arr[i];
        }
        for (int i = 0; i < arr.size()-1; ++i) {
            if (arr[i+1] - arr[i] == Min)
                res.push_back({arr[i], arr[i+1]});
        }
        return res;
    }
};
// @lc code=end

