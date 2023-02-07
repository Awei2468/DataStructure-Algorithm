/*
 * @lc app=leetcode id=1832 lang=cpp
 *
 * [1832] Check if the Sentence Is Pangram
 */

// @lc code=start
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int letter[26] = {0};
        bool res = true;
        for (char c : sentence) {
            int delta = c - 'a';
            letter[delta]++;
        }
        for (int i = 0; i < 26; ++i) {
            if (!letter[i]) {
                res = false;
                break;
            }
        }
        return res;
    }
};
// @lc code=end

