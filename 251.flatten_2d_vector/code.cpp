class Vector2D {
private:
    vector<vector<int>>::iterator it, end;
    vector<int>::iterator curIt, nextIt;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        it = vec2d.begin();
        end = vec2d.end();
        if (it != end) nextIt = it->begin();
    }

    int next() {
        curIt = nextIt++;
        return *curIt;
    }

    bool hasNext() {
        while (it != end) {
            if (nextIt != it->end()) return true;
            it++;
            if (it == end) break;
            nextIt = it->begin();
        }
        return false;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
