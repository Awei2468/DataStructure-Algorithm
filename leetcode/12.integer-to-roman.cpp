/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        int tmp;
        if (num >= 1000) {
            tmp = num / 1000;
            ans += Convert('M', tmp);
            num -= (1000 * tmp);
        }
        if (num >= 900) {
            ans += "CM";
            num -= 900;
        }
        if (num >= 500) {
            ans += "D";
            num -= 500;
        }
        if (num >= 400) {
            ans += "CD";
            num -= 400;
        }
        if (num >= 100) {
            tmp = num / 100;
            ans += Convert('C', tmp);
            num -= (100 * tmp);
        }
        if (num >= 90) {
            ans += "XC";
            num -= 90;
        }
        if (num >= 50) {
            ans += "L";
            num -= 50;
        }
        if (num >= 40) {
            ans += "XL";
            num -= 40;
        }
        if (num >= 10) {
            tmp = num / 10;
            ans += Convert('X', tmp);
            num -= (10 * tmp);
        }
        if (num == 9) {
            ans += "IX";
            num -= 9;
        }
        if (num >= 5) {
            ans += "V";
            num -= 5;
        }
        if (num == 4) {
            ans += "IV";
            num -= 4;
        }
        if (num >= 1) {
            tmp = num;
            ans += Convert('I', tmp);
        }
        return ans;
    }
    string Convert(char ch, int n) {
        string res = "";
        while (n-- > 0) {
            res += ch;
        }
        return res;
    }
};
// @lc code=end

