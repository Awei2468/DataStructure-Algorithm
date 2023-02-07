/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *start = head->next, *temp;
        while (start) {
            for (temp = head; temp != start; temp = temp->next) {
                if (start->val < temp->val) {
                    int record = start->val;
                    start->val = temp->val;
                    temp->val = record;
                }
            }
            start = start->next;
        }
        return head;
    }
};
// @lc code=end

