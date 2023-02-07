/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (!s.size()) return true;
        stack<char> S;
        int cnt = 0, i = 0;
        for (int i = t.size()-1; i >= 0; --i)
            S.push(t[i]);
        while (!S.empty()) {
            if (S.top() == s[i]) {
                ++cnt;
                ++i;
            }
            S.pop();
        }
        return cnt == s.size();
    }
};
// @lc code=end

