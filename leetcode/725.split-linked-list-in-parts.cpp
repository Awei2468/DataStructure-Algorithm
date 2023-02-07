/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k, nullptr);
        if (!head) return res;
        int n = 0, q, m, cnt = 0, i = 0;
        ListNode* cur = head, *pre = nullptr;
        while (cur) {
            cur = cur->next;
            ++n;
        }
        cur = head;
        q = n / k;
        m = n % k;
        if (!m) {
            while (cur) {
                if (!cnt) res[i++] = cur;
                pre = cur;
                cur = cur->next;
                ++cnt;
                if (cnt == q) {
                    pre->next = nullptr;
                    pre = nullptr;
                    cnt = 0;
                }
            }
        }
        else {
            while (cur) {
                if (!cnt) res[i++] = cur;
                pre = cur;
                cur = cur->next;
                ++cnt;
                if (m > 0) {
                    if (cnt == q + 1) {
                        pre->next = nullptr;
                        pre = nullptr;
                        cnt = 0;
                        --m;
                    }
                }
                else {
                    if (cnt == q) {
                        pre->next = nullptr;
                        pre = nullptr;
                        cnt = 0;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

