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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        if (head->next->next == NULL) return head->val == head->next->val;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *pre = slow->next;
        slow->next = NULL;
        if (pre == NULL) return true;
        ListNode *cur = pre->next;
        pre->next = NULL;
        while (cur) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        ListNode *headA = head, *headB = pre;
        while (headB) {
            if (headA->val != headB->val) return false;
            headA = headA->next;
            headB = headB->next;
        }
        return true;
    }
};
