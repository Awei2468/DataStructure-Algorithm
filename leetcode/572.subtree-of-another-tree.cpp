/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
    bool chk = false;
    vector<TreeNode*> v;
    int subDepth;
public:
    /*
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (chk) return true;
        if (root->val == subRoot->val) {
            if (CheckSub(root, subRoot)) return chk = true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    bool CheckSub(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root || !subRoot || root->val != subRoot->val) return false;
        return CheckSub(root->left, subRoot->left) && CheckSub(root->right, subRoot->right);
    }
    */
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        subDepth = getDepth(subRoot);
        dfs(root);
        for (auto &t : v) {
            if (CheckSub(t, subRoot))
                return true;
        }
        return false;
    }
    void dfs(TreeNode* root) {
        if (!root) return;
        if (getDepth(root) == subDepth)
            v.push_back(root);
        dfs(root->left);
        dfs(root->right);
    }
    int getDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(getDepth(root->left), getDepth(root->right));
    }
    bool CheckSub(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root || !subRoot || root->val != subRoot->val) return false;
        return CheckSub(root->left, subRoot->left) && CheckSub(root->right, subRoot->right);
    }
};
// @lc code=end

