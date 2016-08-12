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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return NULL;
        return mergeTwoLists(lists, 0, n);
    }
    ListNode* mergeTwoLists(vector<ListNode*>& lists, int begin, int end) {
        if (end - begin == 1) return lists[begin];
        if (end - begin < 1) return NULL;
        ListNode *a, *b;
        if (end - begin > 2) {
            int mid = (begin + end) >> 1;
            a = mergeTwoLists(lists, begin, mid);
            b = mergeTwoLists(lists, mid, end);
        }
        if (end - begin == 2) {
            a = lists[begin];
            b = lists[begin + 1];
        }
        if (a == NULL) return b;
        if (b == NULL) return a;
        ListNode* head;
        if (a->val < b->val) {
            head = a;
            a = a->next;
        } else {
            head = b;
            b = b->next;
        }
        ListNode* p = head;
        while (a && b) {
            if (a->val < b->val) {
                p->next = a;
                a = a->next;
            } else {
                p->next = b;
                b = b->next;
            }
            p = p->next;
        }
        if (a == NULL) {
            p->next = b;
        } else {
            p->next = a;
        }
        return head;
    }
};
