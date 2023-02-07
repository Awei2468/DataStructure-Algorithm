/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        string t;
        istringstream in(s);
        in >> t;
        return Parsing(t);
    }
    int Parsing(string t) {
        int n = t.size(), sign = 1;
        long num = 0;
        for (int i = 0; i < n; ++i) {
            if (t[i] == '-' || t[i] == '+') {
                if (i) break;
                if (t[i] == '-') sign = -1;
            }
            else if (isAlpha(t[i]))
                break;
            else if (t[i] >= '0' && t[i] <= '9') {
                num *= 10;
                num += (t[i] - '0');
            }
            else if (t[i] == '.') break;
            if (sign == -1)
                if (-num < INT_MIN) return INT_MIN;
            else
                if (num > INT_MAX) return INT_MAX;
        }
        if (sign == -1) return -num;
        else return num;
    }
    bool isAlpha(char c) {
        if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
            return true;
        return false;
    }
};
// @lc code=end

