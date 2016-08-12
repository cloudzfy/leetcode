// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    stack<char> buffer;
    int left;
    bool reachEnd;
public:
    Solution() : left(0), reachEnd(false) {}
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int count = 0;
        while (!buffer.empty() && count < n) {
            buf[count++] = buffer.top();
            buffer.pop();
        }
        if (reachEnd) return count;
        while (count < n) {
            int num = read4(buf + count);
            count += num;
            while (count > n) {
                buffer.push(buf[count - 1]);
                count--;
            }
            if (num < 4) {
                reachEnd = true;
                break;
            }
        }
        return count;
    }
};
