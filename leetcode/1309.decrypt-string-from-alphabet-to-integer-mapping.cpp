/*
 * @lc app=leetcode id=1309 lang=cpp
 *
 * [1309] Decrypt String from Alphabet to Integer Mapping
 */

// @lc code=start
class Solution {
public:
    string freqAlphabets(string s) {
        string res = "";
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '#') {
                res.pop_back();
                res.pop_back();
                res += stoi(s.substr(i-2, 2)) - 1 + 'a';
            }
            else
                res += (s[i] - '1' + 'a');
        }
        return res;
    }
};
// @lc code=end

