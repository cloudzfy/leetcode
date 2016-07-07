class Solution {
public:
    bool isNumber(string s) {
        int state = 0;
        for (int i = 0; i < s.length(); i++) {
            if (state == 0) {
                if (s[i] == ' ') continue;
                if (s[i] == '+' || s[i] == '-') state = 1;
                else if (s[i] <= '9' && s[i] >= '0') state = 2;
                else if (s[i] == '.') state = 3;
                else return false;
            } else if (state == 1) {
                if (s[i] <= '9' && s[i] >= '0') state = 2;
                else if (s[i] == '.') state = 3;
                else return false;
            } else if (state == 2) {
                if (s[i] <= '9' && s[i] >= '0') continue;
                else if (s[i] == '.') state = 4;
                else if (s[i] == ' ') state = 9;
                else if (s[i] == 'e' || s[i] == 'E') state = 6;
                else return false;
            } else if (state == 3) {
                if (s[i] <= '9' && s[i] >= '0') state = 5;
                else return false;
            } else if (state == 4) {
                if (s[i] <= '9' && s[i] >= '0') state = 5;
                else if (s[i] == 'e' || s[i] == 'E') state = 6;
                else if (s[i] == ' ') state = 9;
                else return false;
            } else if (state == 5) {
                if (s[i] <= '9' && s[i] >= '0') continue;
                else if (s[i] == 'e' || s[i] == 'E') state = 6;
                else if (s[i] == ' ') state = 9;
                else return false;
            } else if (state == 6) {
                if (s[i] == '+' || s[i] == '-') state = 7;
                else if (s[i] <= '9' && s[i] >= '0') state = 8;
                else return false;
            } else if (state == 7) {
                if (s[i] <= '9' && s[i] >= '0') state = 8;
                else if (s[i] == ' ') state = 9;
                else return false;
            } else if (state == 8) {
                if (s[i] <= '9' && s[i] >= '0') continue;
                else if (s[i] == ' ') state = 9;
                else return false;
            } else if (state == 9) {
                if (s[i] == ' ') continue;
                else return false;
            }
        }
        return state == 2 || state == 4 || state == 5 || state == 8 || state == 9;
        
    }
};
