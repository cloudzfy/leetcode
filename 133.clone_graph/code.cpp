/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mapped;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        mapped[node] = newNode;
        while (!q.empty()) {
            UndirectedGraphNode *curNode = q.front();
            q.pop();
            UndirectedGraphNode *newCurNode = mapped[curNode];
            for (int i = 0; i < curNode->neighbors.size(); i++) {
                UndirectedGraphNode *nextNode = curNode->neighbors[i];
                if(mapped.find(nextNode) != mapped.end()) {
                    newCurNode->neighbors.push_back(mapped[nextNode]);
                } else {
                    q.push(nextNode);
                    UndirectedGraphNode *newNextNode = new UndirectedGraphNode(nextNode->label);
                    mapped[nextNode] = newNextNode;
                    newCurNode->neighbors.push_back(newNextNode);
                }
            }
        }
        return mapped[node];
    }
};
