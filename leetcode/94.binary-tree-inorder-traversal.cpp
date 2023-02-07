/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        //recursive
        /*
        vector<int> result;
        Inorder(root, result);
        return result;
        */
        //stack
        vector<int> result;
        stack<TreeNode*> S;
        TreeNode* p = root;
        while (p || !S.empty()) {
            if (p) {
                S.push(p);
                p = p->left;
            }
            else {
                TreeNode* back = S.top();
                S.pop();
                result.push_back(back->val);
                p = back->right;
            }
        }
        return result;
    }
    //recursion
    /*
    void Inorder(TreeNode* root, vector<int> &V) {
        if (!root) return;
        Inorder(root->left, V);
        V.push_back(root->val);
        Inorder(root->right, V);
    }
    */
};
// @lc code=end

