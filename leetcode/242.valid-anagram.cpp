/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map <char,int> M;
        for (char ch : t) {
            M[ch]++;
        }
        for (char ch : s) {
            if (!M[ch]) return false;
            M[ch]--;
        }
        for (auto m : M) {
            if (m.second) return false;
        }
        return true;
    }
};
// @lc code=end

