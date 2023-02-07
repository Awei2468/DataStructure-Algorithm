/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = -1;
        int minH = *min_element(heights.begin(), heights.end());
        int maxH = *max_element(heights.begin(), heights.end());
 
        for (int k = minH; k <= maxH; ++k) {
            vector<int> tmp;
            int cnt = 1, maxSeq = 0;
            for (int j = 0; j < heights.size(); ++j) {
                if (heights[j] >= k) tmp.push_back(j);
            }
            for (int j = 0; j < tmp.size(); ++j) {
                if (j + 1 < tmp.size()) {
                    if (tmp[j+1] - tmp[j] == 1)
                        ++cnt;
                    else
                        cnt = 1;
                }
                maxSeq = (cnt >= maxSeq) ? cnt : maxSeq;     
            }
            res = (k * maxSeq > res) ? k * maxSeq : res;
        }
        return res;
    }
};
// @lc code=end

