// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        int sz = 0;

        while (p != nullptr) {
            sz++;
            p = p->next;
        }

        if (sz == n) {
            p = head->next;
            head->next = nullptr;
            return p;
        }

        p = head;
        ListNode* q = p->next;

        while (q != nullptr && --sz > n) {
            p = q;
            q = q->next;
        }

        p->next = q->next;
        q->next = nullptr;

        return head;
    }
};