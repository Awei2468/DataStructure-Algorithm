/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> Res;
        if (root) Helper(root, "", Res);
        return Res;
    }
    void Helper(TreeNode *node, string show, vector<string> &res) {
        if (!node->left && !node->right) res.push_back(show + to_string(node->val));
        if (node->left) Helper(node->left, show + to_string(node->val) + "->", res);
        if (node->right) Helper(node->right, show + to_string(node->val) + "->", res);
    }
};
// @lc code=end

