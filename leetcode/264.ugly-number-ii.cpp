/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution {
public:
    //Solution() {dp[0] = 1;}  //TLE version
    int nthUglyNumber(int n) {
        vector<int> res;
        res.push_back(1);
        int i2 = 0, i3 = 0, i5 = 0;
        while (res.size() < n) {
            int M2 = res[i2] * 2, M3 = res[i3] * 3, M5 = res[i5] * 5;
            int Min = min(M2, min(M3, M5));
            if (Min == M2) ++i2;
            if (Min == M3) ++i3;
            if (Min == M5) ++i5;
            res.push_back(Min);
        }
        return res[n-1];
        /*
        int i, res = 0;
        if (dp[n-1] > 0) return dp[n-1];
        for (i = dp[record-1] + 1; i <= INT_MAX; ++i) {
            if (isUgly(i)) {
                ++record;
                dp[record-1] = i;
            }
            if (record == n) break;
        }
        return i;
        */
    }
    /*
    bool isUgly(int n) {
        if (n < 1) return false;
        return (Calculate(n) == 1) ? true : false;
    }
    int Calculate(int x) {
        while (!(x % 2) || !(x % 3) || !(x % 5)) {
            if (!(x % 2))
                x /= 2;
            if (!(x % 3))
                x /= 3;
            if (!(x % 5))
                x /= 5;
        }
        return x;
    }
    */
/*
private:
    int dp[1690] = {0};
    int record = 1;
*/
};
// @lc code=end

