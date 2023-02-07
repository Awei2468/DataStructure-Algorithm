/*
 * @lc app=leetcode id=728 lang=cpp
 *
 * [728] Self Dividing Numbers
 */

// @lc code=start
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; ++i) {
            if (CheckNumber(i))
                res.push_back(i);
        }
        return res;
    }
    bool CheckNumber(int n) {
        int origin = n;
        while (n > 0) {
            int tmp = n % 10;
            if (!tmp || origin % tmp) {
                return false;
            }
            n /= 10;
        }
        return true;
    }
};
// @lc code=end

