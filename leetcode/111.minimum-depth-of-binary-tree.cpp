/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int round = 0;
    int minDepth(TreeNode* root) {
        /*
        ++round;
        if (!root && round == 1) return 0;
        else if (!root && round > 1) return __INT_MAX__;
        else if (root && !root->left && !root->right) return 1;
        return 1 + min(minDepth(root->left), minDepth(root->right));
        */
       
       if (!root) return 0;
       if (!root->left) return 1 + minDepth(root->right);
       if (!root->right) return 1 + minDepth(root->left);
       return 1 + min(minDepth(root->left), minDepth(root->right));

    }
};
// @lc code=end

