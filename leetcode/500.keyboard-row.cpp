/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 */

// @lc code=start
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        unordered_map <char,int> M;
        M['A'] = M['a'] = 2;
        M['B'] = M['b'] = 3;
        M['C'] = M['c'] = 3;
        M['D'] = M['d'] = 2;
        M['E'] = M['e'] = 1;
        M['F'] = M['f'] = 2;
        M['G'] = M['g'] = 2;
        M['H'] = M['h'] = 2;
        M['I'] = M['i'] = 1;
        M['J'] = M['j'] = 2;
        M['K'] = M['k'] = 2;
        M['L'] = M['l'] = 2;
        M['M'] = M['m'] = 3;
        M['N'] = M['n'] = 3;
        M['O'] = M['o'] = 1;
        M['P'] = M['p'] = 1;
        M['Q'] = M['q'] = 1;
        M['R'] = M['r'] = 1;
        M['S'] = M['s'] = 2;
        M['T'] = M['t'] = 1;
        M['U'] = M['u'] = 1;
        M['V'] = M['v'] = 3;
        M['W'] = M['w'] = 1;
        M['X'] = M['x'] = 3;
        M['Y'] = M['y'] = 1;
        M['Z'] = M['z'] = 3;
        for (string wrd : words) {
            bool check = true;
            for (int i = 0; i < wrd.size(); ++i) {
                if (i + 1 < wrd.size() && M[wrd[i + 1]] != M[wrd[i]]) {
                    check = false;
                    break;
                }
            }
            if (check) res.push_back(wrd);
        }
        return res;
    }
};
// @lc code=end

