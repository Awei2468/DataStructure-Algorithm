/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        if (n == 1) return res;
        for (int i = 2; i <= n; ++i) {
            int cnt = 0, k = 0;
            string tmp = "";
            for (int j = 0; j < res.size(); ++j) {
                if (res[j] == res[k]) {
                    ++cnt;
                }
                else {
                    tmp += (to_string(cnt) + res[k]);
                    cnt = 1; 
                    k = j;
                }
            }
            tmp += (to_string(cnt) + res[k]);
            res = tmp;
        }
        return res;
    }
};
// @lc code=end

