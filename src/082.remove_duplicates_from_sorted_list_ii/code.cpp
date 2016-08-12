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
        if (head == NULL || head->next == NULL) return head;
        ListNode* p = head;
        while (p->next != NULL && p->val == p->next->val) {
            p = p->next;
        }
        if (p != head) return deleteDuplicates(p->next);
        head->next = deleteDuplicates(p->next);
        return head;
    }
};
