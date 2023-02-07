/*
 * @lc app=leetcode id=1399 lang=cpp
 *
 * [1399] Count Largest Group
 */

// @lc code=start
class Solution {
public:
    int countLargestGroup(int n) {
        int nums[37] = {0};
        int Max = -1, ans = 0;
        for (int i = 1; i <= n; ++i) {
            int t = Cal(i);
            nums[t]++;
            if (nums[t] > Max) Max = nums[t];
        }
        for (int i = 1; i < 37; ++i) {
            if (nums[i] == Max)
                ++ans;
        }
        return ans;
    }
    int Cal(int x) {
        int res = 0;
        while (x > 0) {
            res += (x % 10);
            x /= 10;
        }
        return res;
    }
};
// @lc code=end

