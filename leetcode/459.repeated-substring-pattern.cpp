/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).substr(1, 2 * s.size() - 2).find(s) == string::npos ? false : true;
        /*
        int letter[26] = {0}, Min = INT_MAX, seg = 0, n = s.size(), gcd = 0;
        for (char &c : s) letter[c - 'a']++;
        for (int i = 0; i < 26; ++i) {
            if (letter[i] > 1 && letter[i] < Min)
                Min = letter[i];
            else if (letter[i] == 1)
                return false; 
        }
        for (int i = Min; i > 0; --i) {  //find gcd
            bool chk = true;
            for (int j = 0; j < 26; ++j) {
                if (letter[j] % i) {
                    chk = false;
                    break;
                }
            }
            if (chk) {
                gcd = i;
                break;
            }
        }
        for (int k = gcd; k > 1; --k) {  //polling gcd's factor
            if (gcd % k) continue;
            seg = 0;
            bool chk = true;
            for (int i = 0; i < 26; ++i) {
                seg += letter[i] / k;
            }
            for (int i = seg; i < n; i += seg) {
                if (s.substr(0, seg) != s.substr(i, seg)) {
                    chk = false;
                    break;
                }
            }
            if (chk) return true;
        }
        return false;
        */
    }
};
// @lc code=end

