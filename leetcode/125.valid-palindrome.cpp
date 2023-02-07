/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size()-1;
        bool L, R;
        while (start < end) {
            L = (s[start] >= 'a' && s[start] <= 'z') || (s[start] >= 'A' && s[start] <= 'Z') || (s[start] >= '0' && s[start] <= '9');
            R = (s[end] >= 'a' && s[end] <= 'z') || (s[end] >= 'A' && s[end] <= 'Z') || (s[end] >= '0' && s[end] <= '9');
            if (L && R) {
                if (tolower(s[start]) != tolower(s[end]))
                    return false;
                ++start;
                --end;
            }
            else if (!L && R) {
                ++start;
            }
            else if (L && !R) {
                --end;
            }
            else {
                ++start;
                --end;
            }
        }
        return true;
    }
};
// @lc code=end

