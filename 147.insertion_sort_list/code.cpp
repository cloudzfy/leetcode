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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead = NULL;
        while (head != NULL) {
            ListNode *p = head;
            head = head->next;
            if (newHead == NULL) {
                newHead = p;
                p->next = NULL;
                continue;
            }
            if (p->val < newHead->val) {
                p->next = newHead;
                newHead = p;
                continue;
            }
            ListNode *pre = newHead;
            ListNode *cur = newHead->next;
            while (cur != NULL && cur->val < p->val) {
                pre = pre->next;
                cur = cur->next;
            }
            pre->next = p;
            p->next = cur;
        }
        return newHead;
    }
};
