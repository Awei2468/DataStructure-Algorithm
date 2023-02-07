/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int LeftHeight = 1 + GetDepth(root->left);
        int RightHeight = 1 + GetDepth(root->right);
        if (abs(LeftHeight-RightHeight) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right); //need to consider sub-tree situation
    }

    int GetDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(GetDepth(root->left), GetDepth(root->right));
    }
};
// @lc code=end

