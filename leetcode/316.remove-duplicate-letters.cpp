/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res = "";
        int letter[26] = {0};
        bool chk[26] = {false};
        for (char &ch : s)
            letter[ch - 'a']++;
        for (char &ch : s) {
            letter[ch - 'a']--;
            if (!res.size()) {
                res += ch;
                chk[ch - 'a'] = true;
                continue;
            }
            if (chk[ch - 'a']) continue;
            while (ch < res.back() && res.size() && letter[res.back() - 'a'] > 0) {
                chk[res.back() - 'a'] = false;
                res.pop_back();
            }
            res += ch;
            chk[ch - 'a'] = true;
        }
        return res;
    }
};
// @lc code=end

