/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        int res = 0, cnt = 0;
        do {
            res = 0;
            do {
                int tmp = n % 10;
                res += tmp*tmp;
                n /= 10;
            } while (n > 0);
            n = res;
            ++cnt;
        } while (n != 1 && n != 10 && n != 100 && n != 1000 && cnt <= 10);
        return (n == 1 || n == 10 || n == 100 || n == 1000) ? true : false;
    }
};
// @lc code=end

