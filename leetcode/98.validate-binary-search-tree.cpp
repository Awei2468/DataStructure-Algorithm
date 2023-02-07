/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        /*//LVR method
        vector<int> res;
        inorder(root, res);
        int n = res.size();
        for (int i = 1; i < n; ++i) {
            if (res[i] <= res[i-1])
                return false;
        }
        return true;
        */
       return validBST(root, (long)INT_MIN - 1, (long)INT_MAX + 1);
    }
    /*
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    */
    bool validBST(TreeNode* root, long min, long max) {
        if (!root) return true;
        if (root->val <= min || root->val >= max) return false;
        return validBST(root->left, min, root->val) && validBST(root->right, root->val, max);
    }
};
// @lc code=end

