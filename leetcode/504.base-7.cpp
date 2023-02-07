/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        string S1;
        int temp = 0, i = 1;
        S1 = (num >= 0) ? "":"-";
        num = (num > 0) ? num:-num;
        while (num) {
            temp += (num % 7)*i;                
            num /= 7;
            i *= 10;
        }
        return S1 += to_string(temp);
    }
};
// @lc code=end

