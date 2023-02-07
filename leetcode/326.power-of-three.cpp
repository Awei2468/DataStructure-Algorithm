/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        int r;
        if (!n) return false;
        if (n == 1 || n == 3) return true;
        do {
            r = n % 3;
            n /= 3;   
            if (r) return false;
        } while (n > 3);
        if (n == 3) 
            return true;
        else 
            return false;
    }
};
// @lc code=end

