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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *cur = slow->next;
        slow->next= NULL;
        ListNode *post = cur->next;
        cur->next = NULL;
        while (post) {
            ListNode *tmp = post->next;
            post->next = cur;
            cur = post;
            post = tmp;
        }
        ListNode *headB = cur;
        ListNode *headA = head;
        while (headB) {
            ListNode *tmp1 = headA->next;
            ListNode *tmp2 = headB->next;
            headA->next = headB;
            headB->next = tmp1;
            headA = tmp1;
            headB = tmp2;
        }
    }
};
