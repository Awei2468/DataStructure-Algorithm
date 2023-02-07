/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 */

// @lc code=start
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0;
        unordered_set<string> passed, tested;
        for (string str : words) {
            if (passed.count(str) || tested.count(str)) {
                if (passed.count(str)) ++res;
                continue;
            }
            int i = 0, j = 0;
            while (i < s.size() && j < str.size()) {
                if (s[i] == str[j])
                    ++j;
                ++i;
            }
            if (j == str.size()) {
                ++res;
                passed.insert(str);
            }
            else
                tested.insert(str);
        }
        return res;
    }
};
// @lc code=end

