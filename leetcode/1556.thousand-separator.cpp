/*
 * @lc app=leetcode id=1556 lang=cpp
 *
 * [1556] Thousand Separator
 */

// @lc code=start
class Solution {
public:
    string thousandSeparator(int n) {
        if (!n) return "0";
        string ans;
        int cnt = 0;
        while (n > 0) {
            ++cnt;
            ans.insert(0, to_string(n % 10));
            n /= 10;
            if (cnt == 3) {
                ans.insert(0, ".");
                cnt = 0;
            }
        }
        if (ans[0] == '.') ans.erase(0, 1);
        return ans;
    }
};
// @lc code=end

