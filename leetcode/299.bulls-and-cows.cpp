/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size(), A = 0, B = 0, hash[10] = {0};
        unordered_set<int> ust;
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) {
                ++A;
                ust.insert(i);
            }
            else {
                hash[secret[i] - '0']++;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (ust.count(i)) continue;
            if (hash[guess[i] - '0'] > 0) {
                ++B;
                hash[guess[i] - '0']--;
            }
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};
// @lc code=end

