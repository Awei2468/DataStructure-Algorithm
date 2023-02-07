/*
 * @lc app=leetcode id=1897 lang=cpp
 *
 * [1897] Redistribute Characters to Make All Strings Equal
 */

// @lc code=start
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int lowercase[26] = {0};
        for (string word : words) {
            for (char ch : word) {
                int delta = ch - 'a';
                lowercase[delta]++;
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (lowercase[i] % words.size()) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

