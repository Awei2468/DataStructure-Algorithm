/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map <char,string> M;
        int idx = 0;
        for (char ch : pattern) {
            string tmp = "";
            while (s[idx] >= 'a' && s[idx] <= 'z') {
                tmp += s[idx];
                ++idx;
            }
            ++idx;
            if (M[ch] != "") {
                if (M[ch] != tmp)
                    return false;
            }
            else {
                for (auto m : M) {
                    if (m.second == tmp && m.first != ch)
                        return false;
                }
                M[ch] = tmp;
            }
        }
        if (idx != s.size() + 1) return false; 
        return true;
    }
};
// @lc code=end

