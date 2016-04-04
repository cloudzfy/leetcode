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
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] == NULL) continue;
            q.push(lists[i]);
        }
        if (q.empty()) return NULL;
        ListNode* head = q.top();
        q.pop();
        ListNode *p = head;
        if (p->next != NULL) {
            p = p->next;
            q.push(p);
        }
        ListNode *cur = head;
        while (!q.empty()) {
            p = q.top();
            cur->next = p;
            cur = p;
            q.pop();
            if (p->next != NULL) {
                p = p->next;
                q.push(p);
            }
        }
        return head;
    }
    struct cmp {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
};
