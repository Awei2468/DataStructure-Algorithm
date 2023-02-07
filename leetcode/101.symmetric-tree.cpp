/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool CompareLR(TreeNode *L, TreeNode *R) {
        if (!L && !R) return true;
        if ((!L && R) || (L && !R) || (L->val != R->val)) return false;
        return CompareLR(L->right, R->left) && CompareLR(L->left, R->right);
    }
    bool isSymmetric(TreeNode* root) {
        return CompareLR(root->left, root->right);
    }
};
// @lc code=end

