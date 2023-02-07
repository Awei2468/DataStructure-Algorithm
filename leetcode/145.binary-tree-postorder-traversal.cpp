/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> Res;
        //postorder(root, Res);
        if (!root) return Res;
        stack<TreeNode*> S;
        S.push(root);

        while (!S.empty()) {
            TreeNode *node = S.top();
            
            if (!node->left && !node->right) {
                S.pop();
                Res.push_back(node->val);
            }

            if (node->right) {
                S.push(node->right);
                node->right = NULL;
            }

            if (node->left) {
                S.push(node->left);
                node->left = NULL;
            }
        }
        return Res;
    }
    /*
    void postorder(TreeNode *root, vector<int> &res) {
        if (root) {
            postorder(root->left, res);
            postorder(root->right, res);
            res.push_back(root->val);
        }
    }
    */
};
// @lc code=end

