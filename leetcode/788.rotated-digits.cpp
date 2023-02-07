/*
 * @lc app=leetcode id=788 lang=cpp
 *
 * [788] Rotated Digits
 */

// @lc code=start
class Solution {
private:
    int dp[10001] = {0};
public:
    Solution() {
        for (int i = 0; i < 10; ++i) {
            if(i == 0 || i == 1 || i == 8)
                dp[i] = 1;
            else if (i == 2 || i == 5 || i == 6 || i == 9) {
                dp[i] = 2;
            }
        }
    }
    int rotatedDigits(int n) {
        int cnt = 0;
        for (int i = 0; i <= n; ++i) {
            if (dp[i] > 0) {
                if (dp[i] == 2)
                    ++cnt;
                continue;
            }
            int tmp1 = dp[i/10];
            int tmp2 = dp[i%10];
            if (tmp1 == 1 && tmp2 == 1)
                dp[i] = 1;
            else if (tmp1 >= 1 && tmp2 >= 1) {
                dp[i] = 2;
                ++cnt;
            }
        }
        return cnt;
    }
};
// @lc code=end

