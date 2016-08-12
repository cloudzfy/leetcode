/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> mapped;
        bool isHead = true;
        RandomListNode *node = head, *newHead = NULL;
        while (node != NULL) {
            RandomListNode *newNode;
            if (mapped.find(node) == mapped.end()) {
                newNode = new RandomListNode(node->label);
                mapped[node] = newNode;
            } else newNode = mapped[node];
            if (node->next) {
                RandomListNode *newNext;
                if (mapped.find(node->next) == mapped.end()) {
                    newNext = new RandomListNode(node->next->label);
                    mapped[node->next] = newNext;
                } else newNext = mapped[node->next];
                newNode->next = newNext;
            }
            if (node->random) {
                RandomListNode *newRandom;
                if (mapped.find(node->random) == mapped.end()) {
                    newRandom = new RandomListNode(node->random->label);
                    mapped[node->random] = newRandom;
                } else newRandom = mapped[node->random];
                newNode->random = newRandom;
            }
            if (isHead) {
                newHead = newNode;
                isHead = false;
            }
            node = node->next;
        }
        return newHead;
    }
};
