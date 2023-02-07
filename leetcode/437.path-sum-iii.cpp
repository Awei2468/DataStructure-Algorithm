/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
    int res = 0, sum;
    unordered_map<int,int> saw;
public:
    int pathSum(TreeNode* root, int targetSum) {
        /*
        if (!root) return 0;
        return dfs(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
        */
        sum = targetSum;
        saw[0] = 1;
        dfs(root, 0);
        return res;
    }
    /*
    int dfs(TreeNode *root, int targetSum) {
        if (!root) return 0;
        targetSum -= root->val;
        return !targetSum + dfs(root->left, targetSum) + dfs(root->right, targetSum);
    }*/
    void dfs(TreeNode *root, int pSum) {
        if (!root) return;
        pSum += root->val;
        res += saw[pSum - sum];
        ++saw[pSum];
        dfs(root->left, pSum);
        dfs(root->right, pSum);
        --saw[pSum];
    }
};
// @lc code=end

