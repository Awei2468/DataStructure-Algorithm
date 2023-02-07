/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
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
//DFS
/*
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *newHead = new TreeNode(), *cur = newHead;
        inorder(root, cur);
        return newHead->right;
    }
    void inorder(TreeNode *root, TreeNode *&cur) {
        if (!root) return;
        inorder(root->left, cur);
        TreeNode *newRight = new TreeNode(root->val);
        cur->left = nullptr;
        cur->right = newRight;
        cur = newRight;
        inorder(root->right, cur);
    }
};
*/
//BFS
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *newHead = new TreeNode(), *cur = newHead;
        stack<TreeNode*> stk;
        TreeNode *node = root;
        while (!stk.empty() || node) {
            if (node) {
                stk.push(node);
                node = node->left;
            }
            else {
                TreeNode *t = stk.top();
                stk.pop();
                TreeNode *newRight = new TreeNode(t->val);
                cur->right = newRight;
                cur = newRight;
                node = t->right;
            }
        }
        return newHead->right;
    }
};
// @lc code=end

