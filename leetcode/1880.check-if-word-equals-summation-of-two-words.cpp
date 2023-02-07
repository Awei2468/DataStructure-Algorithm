/*
 * @lc app=leetcode id=1880 lang=cpp
 *
 * [1880] Check if Word Equals Summation of Two Words
 */

// @lc code=start
class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        unsigned int sum = 0, target = 0, tmp = 1;
        for (int i = firstWord.size()-1; i >= 0; --i) {
            sum += (firstWord[i]-'a') * tmp;
            tmp *= 10;
        }
        tmp = 1;
        for (int i = secondWord.size()-1; i >= 0; --i) {
            sum += (secondWord[i]-'a') * tmp;
            tmp *= 10;
        }
        tmp = 1;
        for (int i = targetWord.size()-1; i >= 0; --i) {
            target += (targetWord[i]-'a') * tmp;
            tmp *= 10;
        }
        return (sum == target) ? true : false;
    }
};
// @lc code=end

