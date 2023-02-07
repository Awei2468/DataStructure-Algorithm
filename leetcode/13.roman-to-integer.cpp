/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start

class Solution {
public:
    int romanToInt(string s) {
        int number = 0, len = s.size();
        s += 'Z';

        int hash[26] = {0};
        hash['I' - 'A'] = 1;
        hash['V' - 'A'] = 5;
        hash['X' - 'A'] = 10;
        hash['L' - 'A'] = 50;
        hash['C' - 'A'] = 100;
        hash['D' - 'A'] = 500;
        hash['M' - 'A'] = 1000;

        for (int i = 0; i < len; ++i) {
            if (hash[s[i] - 'A'] >= hash[s[i+1] - 'A'])
                number += hash[s[i] - 'A'];
            else {
                number += (hash[s[i+1] - 'A'] - hash[s[i] - 'A']);
                i += 1;
            }
        }
        return number;
    }
};
// @lc code=end

