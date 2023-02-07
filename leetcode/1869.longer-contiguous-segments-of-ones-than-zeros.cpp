/*
 * @lc app=leetcode id=1869 lang=cpp
 *
 * [1869] Longer Contiguous Segments of Ones than Zeros
 */

// @lc code=start
class Solution {
public:
    bool checkZeroOnes(string s) {
        if (s.size() == 1 && s[0] == '1') return true;
        else if (s.size() == 1) return false;
        int cnt0 = 1, cnt1 = 1;
        int max0 = 0, max1 = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0' && (i+1 < s.size()) && s[i+1] == '0') {
                ++cnt0;
            }
            else if (s[i] == '1' && (i+1 < s.size()) && s[i+1] == '1') {
                ++cnt1;
            }
            else {
                if (cnt0 > max0) max0 = cnt0;
                if (cnt1 > max1) max1 = cnt1;
                cnt0 = 1;
                cnt1 = 1;
            }
        }
        return (max1 > max0 && cnt1 != s.size()) ? true : false;
    }
};
// @lc code=end

