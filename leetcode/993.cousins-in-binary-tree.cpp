/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
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
    bool isCousins(TreeNode* root, int x, int y) {
        int hx = 0, hy = 0;
        bool sameParent = false;
        Helper(root, 0, hx, hy, x, y, sameParent);
        return (!sameParent) && (hx == hy);
    }
    void Helper(TreeNode* node, int tmp, int &hx, int &hy, int &targetX, int &targetY, bool &same) {
        if (!node) return;
        if (node->val == targetX) hx = tmp;
        if (node->val == targetY) hy = tmp;
        if (node->left && node->right) {
            int L = node->left->val, R = node->right->val;
            if ((L == targetX && R == targetY) || (L == targetY && R == targetX))
                same = true;
        }
        Helper(node->left, tmp+1, hx, hy, targetX, targetY, same);
        Helper(node->right, tmp+1, hx, hy, targetX, targetY, same);
    }
};
// @lc code=end

