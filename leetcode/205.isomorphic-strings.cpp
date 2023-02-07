/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash1[256] = {0}, hash2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (hash1[s[i]] != hash2[t[i]]) return false;
            hash1[s[i]] = i + 1;
            hash2[t[i]] = i + 1;
        }
        return true;
    }
};
// @lc code=end

