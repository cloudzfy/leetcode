class Stack {
private:
    queue<int> a, b;
public:
    // Push element x onto stack.
    void push(int x) {
        a.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while (!a.empty()) {
            int x = a.front();
            a.pop();
            if (a.empty()) break;
            b.push(x);
        }
        while (!b.empty()) {
            int x = b.front();
            b.pop();
            a.push(x);
        }
    }

    // Get the top element.
    int top() {
        int ans = 0;;
        while (!a.empty()) {
            int x = a.front();
            a.pop();
            b.push(x);
            if (a.empty()) ans = x;
        }
        while (!b.empty()) {
            int x = b.front();
            b.pop();
            a.push(x);
        }
        return ans;
    }

    // Return whether the stack is empty.
    bool empty() {
        return a.empty();
    }
};
