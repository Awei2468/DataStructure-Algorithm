/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    void recoverTree(TreeNode* root) {
        TreeNode *m1 = nullptr, *m2 = nullptr, *pre = nullptr;
        inorder(root, &pre, &m1, &m2);
        if (m1 && m2) {
            int tmp = m1->val;
            m1->val = m2->val;
            m2->val = tmp;
        }
    }
    void inorder(TreeNode *root, TreeNode **pre, TreeNode **m1, TreeNode **m2) {
        if (!root) return;
        if (root->left) {
            inorder(root->left, pre, m1, m2);
        }
        if (*pre && (*pre)->val > root->val) {
            if (*m1 == nullptr) {
                *m1 = *pre;
                *m2 = root;
            }
            else {
                *m2 = root;
            }
            cout << (*m1)->val << endl;
            cout << (*m2)->val << endl;
        }
        *pre = root;
        if (root->right) {
            inorder(root->right, pre, m1, m2);
        }
    }
};
// @lc code=end

