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
        ListNode *newHead = new ListNode(0);
        while (head) {
            ListNode *p1 = newHead, *p2;
            while (p1->next && p1->next->val < head->val) {
                p1 = p1->next;
            }
            p2 = p1->next;
            p1->next = head;
            head = head->next;
            p1->next->next = p2;
        }
        return newHead->next;
    }
};
