/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */

// @lc code=start
class Solution {
private:
    vector<string> res;
    int H, M, cnt, b;
    string ans;
public:
    vector<string> readBinaryWatch(int turnedOn) {
        dfs("", turnedOn);
        return res;
    }
    void dfs(string tmp, int turnedOn) {
        if (tmp.size() == 10) {
            if (CountOne(tmp) == turnedOn && H < 12 && M < 60) {
                ans = (M >= 10) ? to_string(H) + ":" + to_string(M) : to_string(H) + ":0" + to_string(M);
                res.push_back(ans);
            }
            return;
        }
        dfs(tmp + '1', turnedOn);
        dfs(tmp + '0', turnedOn);
    }
    int CountOne(string str) {
        cnt = 0, H = 0, M = 0, b = 1;
        for (int i = 9; i >= 0; --i) {
            if (i >= 4) {
                if (str[i] == '1') M |= b;
                b <<= 1;
            }
            if (i <= 3) {
                if (i == 3) b = 1;
                if (str[i] == '1') H |= b;
                b <<= 1;
            }
            if (str[i] == '1') ++cnt;
        }
        return cnt;
    }
};
// @lc code=end

