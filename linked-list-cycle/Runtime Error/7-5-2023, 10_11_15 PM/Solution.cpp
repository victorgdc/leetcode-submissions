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
        unordered_map<ListNode*, int> hash;

        // if (head != NULL) {
            while (true) {
                hash[head]++;
                if (hash[head] == 2) return true;
                if (head->next == NULL) break;
                head = head->next;
            }
        // }
        
        return false;
    }
};