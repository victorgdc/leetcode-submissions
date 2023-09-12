// https://leetcode.com/problems/middle-of-the-linked-list

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
    ListNode* middleNode(ListNode* head) {
        int tam = 0;
        int i = 0;
        ListNode* p = head;

        while (p != NULL) {
            tam++;
            p = p->next;
        }
        tam = tam/2;
        p = head;

        while (i != tam) {
            i++;
            p = p->next;
        }
        
        return p;
    }
};