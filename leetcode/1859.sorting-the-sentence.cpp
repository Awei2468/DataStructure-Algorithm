/*
 * @lc app=leetcode id=1859 lang=cpp
 *
 * [1859] Sorting the Sentence
 */

// @lc code=start
class Solution {
public:
    string sortSentence(string s) {
        string res = "";
        map <int,string> M;
        string tmp = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i]-'0' >= 1 && s[i]-'0' <= 9) {
                M[s[i]-'0'] = tmp;
            }
            else if (s[i] == ' ') {
                tmp = "";
                continue;
            }
            else {
                tmp += s[i];
            }
        }
        for (auto m : M) {
            res += m.second;
            res += " ";
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end

