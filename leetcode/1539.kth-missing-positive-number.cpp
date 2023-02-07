/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 */

// @lc code=start
class Solution {
private:
    vector<pair<int,bool>> nums;
public:
    Solution() {
        for (int i = 0; i < 2000; ++i)
            nums.push_back(make_pair(i+1, true));
    }
    int findKthPositive(vector<int>& arr, int k) {
        int cnt = 0, ans;
        for (int n : arr) {
            nums[n-1].second = false;
        }
        for (auto num : nums) {
            if (num.second)
                ++cnt;
            if (cnt == k) {
                ans = num.first;
                break;
            }
        }
        for (int n : arr) {
            nums[n-1].second = true;
        }
        return ans;
    }
};
// @lc code=end

