/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int count = 0, i;
        if (digits[digits.size()-1] != 9) {
            digits[digits.size()-1] += 1;
        }
        else {
            for (i = digits.size()-1; i >= 0; --i) {
                if (digits[i] == 9)
                    ++count;
                else
                    break;
            }
            if (count == digits.size()) {
                digits.resize(digits.size()+1, 0);
                for (int i = 1; i < digits.size(); ++i) 
                    digits[i] = 0;
                digits[0] = 1;
            }
            else {
                for (int k = 0, i = digits.size()-1; k != count ; --i, ++k)
                    digits[i] = 0;
                digits[i] += 1;
            }
        }
        return digits;
    }
};
// @lc code=end

