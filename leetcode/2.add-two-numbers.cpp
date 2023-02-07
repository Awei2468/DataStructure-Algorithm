/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0;
        ListNode *head = new ListNode(0), *step;
        
        step = head;
        while (l1 && l2) {
            ListNode *newNode = new ListNode();
            sum = l1->val + l2->val;
            
            if (carry) {
                sum += 1;
                carry = 0;
            }
            if (sum >= 10) {
                newNode->val = sum - 10;
                carry = 1;
            }
            else {
                newNode->val = sum;
            }
            l1 = l1->next;
            l2 = l2->next;
            step->next = newNode;
            step = newNode;
        }
        sum = 0;

        while (l1) {
            ListNode *newNode = new ListNode();
            sum = l1->val;
            if (carry) { 
                sum += 1;
                carry = 0;
            }
            if (sum >= 10) {
                newNode->val = sum - 10;
                carry = 1;
            }
            else {
                newNode->val = sum;
            }
            l1 = l1->next;
            step->next = newNode;
            step = newNode;
        }

        while (l2) {
            ListNode *newNode = new ListNode();
            sum = l2->val;
            if (carry) { 
                sum += 1;
                carry = 0;
            }
            if (sum >= 10) {
                newNode->val = sum - 10;
                carry = 1;
            }
            else {
                newNode->val = sum;
            }
            l2 = l2->next;
            step->next = newNode;
            step = newNode;
        }

        if (carry) {
            ListNode *newNode = new ListNode(1);
            step->next = newNode;
            step = newNode;
        }
        
        return head->next;
    }
};
// @lc code=end

