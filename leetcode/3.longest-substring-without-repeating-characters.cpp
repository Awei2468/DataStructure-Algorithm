/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        unordered_set <char> US;
        int start = 0, end = 0, res = 0;

        while (end < len) {
            if (!US.count(s[end])) {
                US.insert(s[end]);
                res = max(res, end - start + 1);
                ++end;
            }
            else {
                US.erase(s[start]);
                ++start;
            }
        }
        return res;
    }
};
// @lc code=end

