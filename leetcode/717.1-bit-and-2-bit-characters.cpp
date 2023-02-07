/*
 * @lc app=leetcode id=717 lang=cpp
 *
 * [717] 1-bit and 2-bit Characters
 */

// @lc code=start
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        while (i < bits.size()-1) {
            if (bits[i]) i += 2;
            else i++;
        }
        return i == bits.size()-1;
    }
};
// @lc code=end

