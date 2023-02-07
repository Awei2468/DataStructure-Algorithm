/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        /*
        TreeNode *ans = nullptr;
        helper(root1, root2, ans);
        return ans;
        */
        if (!root1) return root2;
        if (!root2) return root1;
        TreeNode* tmp = new TreeNode(root1->val + root2->val);
        tmp->left = mergeTrees(root1->left, root2->left);
        tmp->right = mergeTrees(root1->right, root2->right);
        return tmp;
    }
    /*
    void helper(TreeNode* node1, TreeNode* node2, TreeNode* &res) {
        if (!node1 && !node2) return;
        else if (!node1 && node2) {
            res = new TreeNode(node2->val);
            helper(nullptr, node2->left, res->left);
            helper(nullptr, node2->right, res->right);
        }
        else if (node1 && !node2) {
            res = new TreeNode(node1->val);
            helper(node1->left, nullptr, res->left);
            helper(node1->right, nullptr, res->right);
        }
        else {
            res = new TreeNode(node1->val + node2->val);
            helper(node1->left, node2->left, res->left);
            helper(node1->right, node2->right, res->right);
        }
    }
    */
};
// @lc code=end

