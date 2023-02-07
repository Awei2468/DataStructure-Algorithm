/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map <char,int> M;
        for (char ch : magazine)
            M[ch]++;
        for (char ch : ransomNote) {
            if (M[ch] > 0) M[ch]--;
            else
                return false;
        }
        return true;
    }
};
// @lc code=end

