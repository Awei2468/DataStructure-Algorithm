/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (!x) return true;
        int digit[10], i = 0;
        while (x) {
            digit[i] = x % 10;
            x /= 10;           
            ++i;
        }
        for (int j = 0; j <= (i-1)/2; ++j) {
            if (digit[j] ^ digit[i-1-j])
                return false;
        }
        return true;
    }
};
// @lc code=end

