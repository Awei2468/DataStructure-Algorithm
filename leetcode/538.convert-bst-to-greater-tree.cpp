/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
    int sum = 0, idx = 0;
    vector<int> v;
public:
    TreeNode* convertBST(TreeNode* root) {
        inorder(root);
        int local = 0;
        for (int &i : v) {
            local += i;
            i = sum - local + i;
        }
        inorder2(&root);
        return root;
    }
    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        sum += root->val;
        v.push_back(root->val);
        inorder(root->right);
    }
    void inorder2(TreeNode **root) {
        if (!*root) return;
        inorder2(&(*root)->left);
        (*root)->val = v[idx++];
        inorder2(&(*root)->right);
    }
};
// @lc code=end

