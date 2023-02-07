/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        /*
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
        */
        //not recursive
        ListNode *dummy = new ListNode();
        ListNode *current = dummy;
        //ListNode dummy = ListNode();
        //ListNode* current = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1;
                current = l1;
                l1 = l1->next;
            }
            else if (l1->val > l2->val) {
                current->next = l2;
                current = l2;
                l2 = l2->next;
            }
            else {
                ListNode *newNode = new ListNode(l1->val);
                current->next = newNode;
                current = newNode;
                current->next = l1;
                current = l1;
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        if (l1) current->next = l1;
        if (l2) current->next = l2;
        return dummy->next;
        
    }
};
// @lc code=end

