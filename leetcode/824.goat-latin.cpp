/*
 * @lc app=leetcode id=824 lang=cpp
 *
 * [824] Goat Latin
 */

// @lc code=start
class Solution {
public:
    string toGoatLatin(string sentence) {
        string res = "", tmp = "";
        int cnt = 1;
        for (int i = 0; i < sentence.size(); ++i) {
            if (sentence[i] != ' ') {
                tmp += sentence[i];
            }
            else {
                if (tmp[0] == 'a' || tmp[0] == 'e' || tmp[0] == 'i' || tmp[0] == 'o' || tmp[0] == 'u' || tmp[0] == 'A' || tmp[0] == 'E' || tmp[0] == 'I' || tmp[0] == 'O' || tmp[0] == 'U') {
                    tmp += "ma";
                    int t = cnt;
                    while (t-- > 0)
                        tmp += 'a';
                }
                else {
                    char c = tmp[0];
                    tmp.erase(0, 1);
                    tmp += c;
                    tmp += "ma";
                    int t = cnt;
                    while (t-- > 0)
                        tmp += 'a';
                }
                tmp += " ";
                res += tmp;
                tmp = "";
                ++cnt;
            }
        }
        if (tmp[0] == 'a' || tmp[0] == 'e' || tmp[0] == 'i' || tmp[0] == 'o' || tmp[0] == 'u' || tmp[0] == 'A' || tmp[0] == 'E' || tmp[0] == 'I' || tmp[0] == 'O' || tmp[0] == 'U') {
            tmp += "ma";
            while (cnt-- > 0)
                tmp += 'a';
        }
        else {
            char c = tmp[0];
            tmp.erase(0, 1);
            tmp += c;
            tmp += "ma";
            while (cnt-- > 0)
                tmp += 'a';
        }
        res += tmp;
        return res;
    }
};
// @lc code=end

