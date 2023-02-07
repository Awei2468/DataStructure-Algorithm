/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *current = head, *head_2 = head, *current_2 = head_2;
        if (!head_2) return NULL;
        while (current) {
            if (current->val != current_2->val) {
                current_2->next = current;
                current_2 = current;
            }
            current = current->next;
        }
        current_2->next = NULL;
        return head_2;
    }
};
// @lc code=end

