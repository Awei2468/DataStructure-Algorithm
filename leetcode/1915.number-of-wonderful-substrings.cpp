/*
 * @lc app=leetcode id=1915 lang=cpp
 *
 * [1915] Number of Wonderful Substrings
 */

// @lc code=start
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        if (word.size() == 1) return 1;
        long long res = 0;
        unordered_map <char,int> M;
        for (int i = 0; i < word.size()-1; ++i) {
            int odd = 1;
            res++;
            M[word[i]]++;
            for (int j = i+1; j < word.size(); ++j) {
                M[word[j]]++;
                if (M[word[j]] & 1)
                    ++odd;
                else --odd;
                if (odd <= 1) ++res;
            }
            M.clear();
        }
        return res + 1;
    }
};
// @lc code=end

