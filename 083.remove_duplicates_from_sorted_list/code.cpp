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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        int val = head->val;
        ListNode *pre = head, *cur = head->next;
        while(cur != NULL) {
            if (cur->val == val) {
                pre->next = cur->next;
            } else {
                pre = pre->next;
                val = pre->val;
            }
            cur = cur->next;
        }
        return head;
    }
};
