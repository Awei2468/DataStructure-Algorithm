/*
 * @lc app=leetcode id=1287 lang=cpp
 *
 * [1287] Element Appearing More Than 25% In Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int hash[100001] = {0}, n = arr.size();
        if (n < 4) return arr[0];
        n /= 4;
        for (int &a : arr) {
            hash[a]++;
            if (hash[a] > n) {
                return a;
            }
        }
        return -1;
    }
};
// @lc code=end

