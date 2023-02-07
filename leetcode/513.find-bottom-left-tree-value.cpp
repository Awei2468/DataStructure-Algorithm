/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int res, maxDepth = 0;
public:
    int findBottomLeftValue(TreeNode* root) {
        /*//bfs
        int res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = size; i > 0; --i) {
                TreeNode* node = q.front();
                q.pop();
                if (i == size) res = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right); 
            }
        }
        return res;
        */
        dfs(root, 1);
        return res;
    }
    void dfs(TreeNode *root, int d) {
        if (!root) return;
        if (d > maxDepth) {
            maxDepth = d;
            res = root->val;
        }
        dfs(root->left, d+1);
        dfs(root->right, d+1);
    }
};
// @lc code=end

