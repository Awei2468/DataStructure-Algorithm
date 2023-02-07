/*
 * @lc app=leetcode id=700 lang=cpp
 *
 * [700] Search in a Binary Search Tree
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
    TreeNode* searchBST(TreeNode* root, int val) {
        /*
        TreeNode *node = root, *ans = nullptr;
        while (node) {
            if (val > node->val)
                node = node->right;
            else if (val < node->val)
                node = node->left;
            else {
                ans = node;
                break;
            }
        }
        return ans;
        */
        if (!root) return nullptr;
        if (val > root->val) return searchBST(root->right, val);
        else if (val < root->val) return searchBST(root->left, val);
        else return root;
    }
};
// @lc code=end

