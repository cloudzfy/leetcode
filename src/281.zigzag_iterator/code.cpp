class ZigzagIterator {
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.size() > 0) q.push(make_pair(v1.begin(), v1.end()));
        if (v2.size() > 0) q.push(make_pair(v2.begin(), v2.end()));
    }

    int next() {
        vector<int>::iterator it = q.front().first;
        vector<int>::iterator end = q.front().second;
        q.pop();
        int val = *it;
        it++;
        if (it != end) q.push(make_pair(it, end));
        return val;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
