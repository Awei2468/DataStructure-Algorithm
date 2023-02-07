/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return head;
        ListNode *odd = head, *even = head->next, *evenHead = head->next;
        while (odd->next && odd->next->next) {
            ListNode *t1 = odd->next->next;
            odd->next = t1;
            odd = t1;
            ListNode *t2 = even->next->next;
            even->next = t2;
            even = t2;
        }
        odd->next = evenHead;
        return head;
    }
};
// @lc code=end

