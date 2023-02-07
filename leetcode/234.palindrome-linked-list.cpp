/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> S;
        ListNode *cur = head;
        while (cur) {
            S.push(cur->val);
            cur = cur->next;
        }
        cur = head;
        while (!S.empty()) {
            if (S.top() != cur->val)
                return false;
            S.pop();
            cur = cur->next;
        }
        return true;
    }
};
// @lc code=end

