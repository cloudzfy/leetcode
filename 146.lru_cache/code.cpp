class node {
public:
    int key, value;
    node *pre, *next;
    node() : pre(NULL), next(NULL) {}
    node(int key, int value) : key(key), value(value), pre(NULL), next(NULL) {}
};
class LRUCache{
private:
    node* head;
    node* tail;
    int capacity;
    int used;
    unordered_map<int, node*> m;
public:
    LRUCache(int capacity) : capacity(capacity), used(0) {
        head = new node();
        tail = new node();
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if (m.find(key) == m.end() || m[key] == NULL) return -1;
        node *p = m[key];
        p->pre->next = p->next;
        p->next->pre = p->pre;
        head->next->pre = p;
        p->next = head->next;
        head->next = p;
        p->pre = head;
        return p->value;
    }
    
    void set(int key, int value) {
        node *p;
        if (m.find(key) != m.end() && m[key] != NULL) {
            p = m[key];
            p->pre->next = p->next;
            p->next->pre = p->pre;
        } else {
            p = new node(key, value);
            m[key] = p;
            used++;
        }
        head->next->pre = p;
        p->next = head->next;
        head->next = p;
        p->pre = head;
        p->value = value;
        while (used > capacity) {
            m[tail->pre->key] = NULL;
            tail->pre->pre->next = tail;
            tail->pre = tail->pre->pre;
            used--;
        }
    }
};
