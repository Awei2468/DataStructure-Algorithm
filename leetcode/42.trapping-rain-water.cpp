/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int res = 0;
        stack<int> S;  //put index
        S.push(0);

        for (int i = 1; i < height.size(); ++i) {
            if (S.empty() || height[S.top()] >= height[i])
                S.push(i);
            else {
                while (!S.empty() && height[i] > height[S.top()]) {
                    int t = S.top();
                    S.pop();
                    if (S.empty()) break;
                    int h = min(height[S.top()], height[i]) - height[t];
                    int w = i - S.top() - 1;
                    res += (h * w);
                }
                S.push(i);
            }
        }
        return res;
    }
};
// @lc code=end

