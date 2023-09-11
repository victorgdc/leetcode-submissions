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
        unordered_map<int, int> hash;

        while (true) {
            hash[head->val]++;
            if (hash[head->val] == 2) return true;
            if (head->next == NULL) break;
            head = head->next;
        }

        return false;
    }
};