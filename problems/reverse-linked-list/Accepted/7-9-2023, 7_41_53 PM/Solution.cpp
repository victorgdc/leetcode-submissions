// https://leetcode.com/problems/reverse-linked-list

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
    ListNode* reverseList(ListNode* head) {
        ListNode* p, *q, *r;
        
        if (head == NULL) return head;
        p = head;
        if (p->next == NULL) return p;

        q = p->next;
        r = q->next;
        p->next = NULL;

        while (r != NULL) {
            q->next = p;
            p = q;
            q = r;
            r = r->next;
        }
        q->next = p;
        head = q;

        return head;
    }
};