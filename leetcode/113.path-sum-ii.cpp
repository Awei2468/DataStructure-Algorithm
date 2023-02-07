/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> tmp;
        helper(root, targetSum, tmp, res);
        return res;
    }
    void helper(TreeNode* node, int sum, vector<int> &buf, vector<vector<int>> &res) {
        if (!node) return;
        buf.push_back(node->val);
        if (node->val == sum && !node->left && !node->right)
            res.push_back(buf);
        helper(node->left, sum - node->val, buf, res);
        helper(node->right, sum - node->val, buf, res);
        buf.pop_back();
    }
};
// @lc code=end

