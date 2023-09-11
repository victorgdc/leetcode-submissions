// https://leetcode.com/problems/merge-two-sorted-lists

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* listm = new ListNode(-1);
        ListNode* pointer = listm;

        if (list1 == NULL) return list2;
        else if (list2 == NULL) return list1;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                pointer->next = new ListNode(list1->val);
                pointer = pointer->next;
                list1 = list1->next;
            } 
            else {
                pointer->next = new ListNode(list2->val);
                pointer = pointer->next;
                list2 = list2->next;
            }
        }

        while (list1 != NULL) {
            pointer->next = new ListNode(list1->val);
            pointer = pointer->next;
            list1 = list1->next;
        }

        while (list2 != NULL) {
            pointer->next = new ListNode(list2->val);
            pointer = pointer->next;
            list2 = list2->next;
        }

        return listm->next;        
    }
};