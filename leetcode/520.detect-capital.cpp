/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 1) return true;
        bool chk = true;
        bool FirstCap = (word[0] >= 'A' && word[0] <= 'Z') ? true : false;
        bool SecondCap = (word[1] >= 'A' && word[1] <= 'Z') ? true : false;
        if (!FirstCap && SecondCap)
            return chk = false;
        for (int i = 2; i < word.size(); ++i) {
            if (FirstCap) {
                if (SecondCap) {
                    if (word[i] >= 'a' && word[i] <= 'z') {
                        chk = false;
                        break;
                    }
                }
                else {
                    if (word[i] >= 'A' && word[i] <= 'Z') {
                        chk = false;
                        break;
                    }
                }
            }
            else {
                if (word[i] >= 'A' && word[i] <= 'Z') {
                    chk = false;
                    break;
                }
            }
        }
        return chk;
    }
};
// @lc code=end

