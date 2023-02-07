/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        /*
        vector<int> res;
        int tmp = 0x7fffffff;
        for (int i = 0; i <= n; ++i) {
            int cnt = 0, tmp2 = i & tmp;
            while (tmp2) {
                if (tmp2 & 1)
                    ++cnt;
                tmp2 >>= 1;
            }
            res.push_back(cnt);
        }
        return res;
        */
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            res[i] = res[i & i-1] + 1;
        }
        return res;
    }
};
// @lc code=end

