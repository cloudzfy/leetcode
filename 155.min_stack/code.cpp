class MinStack {
private:
    stack<int> s;
    stack<int> mins;
public:
    void push(int x) {
        s.push(x);
        if (mins.empty()) mins.push(x);
        else if (mins.top() >= x) mins.push(x);
    }

    void pop() {
        if (s.top() == mins.top()) mins.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return mins.top();
    }
};
