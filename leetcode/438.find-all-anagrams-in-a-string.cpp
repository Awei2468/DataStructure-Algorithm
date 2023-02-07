/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (p.size() > s.size()) return res;
        vector<int> letter(26, 0);
        for (char &c : p) letter[c - 'a']++;
        for (int i = 0; i <= s.size()-p.size(); ++i) {
            vector<int> tmp(26, 0);
            for (int j = i; j < i+p.size(); ++j) {
                tmp[s[j] - 'a']++;
            }
            if (tmp == letter)
                res.push_back(i);
        }
        return res;
    }
};
// @lc code=end

