/*
 * @lc app=leetcode id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 */

// @lc code=start
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        int carry = 0, i = num.size()-1;
        while (i >= 0 && k > 0) {
            int tmp = carry + num[i] + k % 10;
            if (tmp >= 10) {
                res.insert(res.begin(), tmp - 10);
                carry = 1;
            }
            else {
                res.insert(res.begin(), tmp);
                carry = 0;
            }
            --i;
            k /= 10;
        }
        while (i >= 0) {
            int tmp = carry + num[i];
            if (tmp >= 10) {
                res.insert(res.begin(), tmp - 10);
                carry = 1;
            }
            else {
                res.insert(res.begin(), tmp);
                carry = 0;
            }
            --i;
        }
        while (k > 0) {
            int tmp = carry + k % 10;
            if (tmp >= 10) {
                res.insert(res.begin(), tmp - 10);
                carry = 1;
            }
            else {
                res.insert(res.begin(), tmp);
                carry = 0;
            }
            k /= 10;
        }
        if (carry) res.insert(res.begin(), 1);
        return res;
    }
};
// @lc code=end

