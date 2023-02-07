/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<int> s_num;
        stack<string> s_str;
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                cnt = cnt * 10 + s[i] - '0';
            }
            else if (s[i] == '[') {
                s_num.push(cnt);
                s_str.push(res);
                cnt = 0;
                res.clear();
            }
            else if (s[i] == ']') {
                int tmp = s_num.top();
                s_num.pop();
                for (int i = 0; i < tmp; ++i) s_str.top() += res;
                res = s_str.top();
                s_str.pop();
            }
            else {
                res += s[i];
            }
        }
        return res;
    }
};
// @lc code=end

