/*
 * @lc app=leetcode id=492 lang=cpp
 *
 * [492] Construct the Rectangle
 */

// @lc code=start
class Solution {
public:
    vector<int> constructRectangle(int area) {      
        vector<int> res;
        int t;
        for (int i = 1; i * i <= area; ++i) {
            if (!(area % i)) t = i;
        }
        res.push_back(area / t);
        res.push_back(t);
        return res;
    }
};
// @lc code=end

