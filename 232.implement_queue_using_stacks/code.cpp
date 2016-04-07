class Queue {
private:
    stack<int> a, b;
public:
    // Push element x to the back of queue.
    void push(int x) {
        a.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while (!a.empty()) {
            int x = a.top();
            a.pop();
            if (a.empty()) break;
            b.push(x);
        }
        while (!b.empty()) {
            int x = b.top();
            b.pop();
            a.push(x);
        }
    }

    // Get the front element.
    int peek(void) {
        int ans = 0;
        while (!a.empty()) {
            int x = a.top();
            a.pop();
            b.push(x);
            if (a.empty()) ans = x;
        }
        while (!b.empty()) {
            int x = b.top();
            b.pop();
            a.push(x);
        }
        return ans;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return a.empty();
    }
};
