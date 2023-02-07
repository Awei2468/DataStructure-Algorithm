/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        int letter[26] = {0};
        for (char ch : s) {
            letter[ch - 'a']++;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (letter[s[i]-'a'] == 1)
                return i;
        }
        return -1;
    }
};
// @lc code=end

