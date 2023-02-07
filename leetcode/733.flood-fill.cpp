/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int target = image[sr][sc];
        if (target != newColor)
            dfs(image, sr, sc, newColor, target);
        return image;
    }
    void dfs(vector<vector<int>>& image, int i, int j, int &newColor, int &tar) {
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != tar)
            return;
        image[i][j] = newColor;
        dfs(image, i+1, j, newColor, tar);
        dfs(image, i-1, j, newColor, tar);
        dfs(image, i, j+1, newColor, tar);
        dfs(image, i, j-1, newColor, tar);
    }
};
// @lc code=end

