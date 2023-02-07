/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    void Sum(string str_max, string str_min, int max, int min, string &res, char carry) {
        int i, k;
        for (i = max-1, k = min-1; i >= 0 && k >= 0; --i, --k) {
            if (str_max[i] == '0' && str_min[k] == '0' && carry == '0') {
                res.insert(0, "0");
                carry = '0';
            }
            else if (str_max[i] == '1' && str_min[k] == '1' && carry == '1') {
                res.insert(0, "1");
                carry = '1';
            }
            else if (str_max[i] == '1' && str_min[k] == '1' && carry == '0' || str_max[i] == '1' && str_min[k] == '0' && carry == '1' || str_max[i] == '0' && str_min[k] == '1' && carry == '1') {
                res.insert(0, "0");
                carry = '1';
            }
            else {
                res.insert(0, "1");
                carry = '0';
            }
        }

        for (int j = i; j >= 0; --j) {
            if (str_max[j] == '0' && carry == '0') {
                res.insert(0, "0");
                carry = '0';
            }
            else if (str_max[j] == '1' && carry == '1') {
                res.insert(0, "0");
                carry = '1';
            }
            else {
                res.insert(0, "1");
                carry = '0';
            }
        }

        if (carry == '1')
            res.insert(0, "1");
    }
    string addBinary(string a, string b) {
        string res;
        char carry = '0';
        int LenMin = (a.length() >= b.length()) ? b.length() : a.length();
        int LenMax = a.length() + b.length() - LenMin;

        if (LenMax == a.length())
            Sum(a, b, LenMax, LenMin, res, carry);
        else
            Sum(b, a, LenMax, LenMin, res, carry);

        return res;
    }
};
// @lc code=end

