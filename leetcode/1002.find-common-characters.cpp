/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        /*
        vector<string> res;
        vector<int> cnt(26, INT_MAX);
        for (string word : words) {
            vector<int> t(26);
            for (char c : word) ++t[c - 'a'];
            for (int i = 0; i < 26; ++i) {
                cnt[i] = min(cnt[i], t[i]);
            }
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                res.push_back(string(1, 'a' + i));
            }
        }
        return res;
        */
        vector<string> res;
        unordered_map <char,int> M;
        for (char c : words[0]) M[c]++;
        for (auto &m : M) {
            char aim = m.first;
            bool chk; int leastCount = INT_MAX;
            for (int j = 1; j < words.size(); ++j) {
                chk = false; int cnt = 0;
                for (char ch : words[j]) {
                    if (aim == ch) {
                        chk = true;
                        cnt++;
                    }
                }
                leastCount = (cnt < leastCount) ? cnt : leastCount;
            }
            if (chk) {
                string tmp;
                tmp.push_back(aim);
                while (leastCount-- > 0 && m.second-- > 0) {
                    res.push_back(tmp);
                }
            }
        }
        return res;
        /*
        vector<string> res;
        unordered_map <char,int> M;
        for (char ch : words[0]) {
            M[ch]++;
        }
        for (int i = 1; i < words.size(); ++i) {
            for (char ch : words[i]) {
                if (M[ch]) M[ch]++;
            }
            CheckExist(words[i], M);
        }
        for (auto m : M) {
            if (m.second && m.second >= words.size()) {
                int round = m.second;
                string tmp;
                tmp.push_back(m.first);
                while (round >= words.size()) {
                    res.push_back(tmp);
                    round -= words.size();
                }
            }
        }
        return res;
        */
    }
    /*
    void CheckExist(string str, unordered_map <char,int> &m) {
        for (auto sub_m : m) {
            int chk = false;
            for (char c : str) {
                if (sub_m.first == c) {
                    chk = true;
                    break;
                }
            }
            if (!chk) {
                char del = sub_m.first;
                m.erase(del);// problem
            }
        }
    }
    */
};
// @lc code=end

