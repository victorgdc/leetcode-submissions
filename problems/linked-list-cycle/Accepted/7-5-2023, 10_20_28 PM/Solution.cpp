// https://leetcode.com/problems/linked-list-cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* p = head, *q = head;

        if (head != NULL){
            while (true) {
                if (p->next == NULL) break;
                p = p->next;
                if (q->next == NULL || q->next->next == NULL) break;
                q = q->next->next;
                if (p == q) return true;
            }
        }
        
        return false;
    }
};