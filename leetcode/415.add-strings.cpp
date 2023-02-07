/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        stack<int> S1, S2;
        int carry = 0;
        for (char ch : num1)
            S1.push(ch - '0');
        for (char ch : num2)
            S2.push(ch - '0');
        while (!S1.empty() && !S2.empty()) {
            int tmp = S1.top() + S2.top() + carry;
            if (tmp >= 10) {
                tmp -= 10;
                ans += to_string(tmp);
                carry = 1;
            }
            else {
                ans += to_string(tmp);
                carry = 0;
            }
            S1.pop();
            S2.pop();
        }
        while (!S1.empty()) {
            int tmp = S1.top() + carry;
            if (tmp >= 10) {
                tmp -= 10;
                ans += to_string(tmp);
                carry = 1;
            }
            else {
                ans += to_string(tmp);
                carry = 0;
            }
            S1.pop();
        }
        while (!S2.empty()) {
            int tmp = S2.top() + carry;
            if (tmp >= 10) {
                tmp -= 10; 
                ans += to_string(tmp);
                carry = 1;
            }
            else {
                ans += to_string(tmp);
                carry = 0;
            }
            S2.pop();
        }
        if (carry) ans += to_string(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

