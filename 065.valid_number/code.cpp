class Solution {
private:
    enum states {
        BEGIN,
        NUM,
        FRAC,
        DOT,
        SIGN,
        INT,
        EXP,
        EXPSIGN,
        DIGIT,
        END
    };
public:
    bool isNumber(string s) {
        states curState = BEGIN;
        for (int i = 0; i < s.length(); i++) {
            if (curState == BEGIN) {
                if (s[i] == ' ') continue;
                else if (s[i] == '.') curState = FRAC;
                else if (s[i] == '+' || s[i] == '-') curState = SIGN;
                else if (isDigit(s[i])) curState = NUM;
                else return false;
            } else if (curState == NUM) {
                if (isDigit(s[i])) continue;
                else if (s[i] == '.') curState = DOT;
                else if (s[i] == 'e') curState = EXP;
                else if (s[i] == ' ') curState = END;
                else return false;
            } else if (curState == FRAC) {
                if (isDigit(s[i])) curState = INT;
                else return false;
            } else if (curState == DOT) {
                if (isDigit(s[i])) curState = INT;
                else if (s[i] == 'e') curState = EXP;
                else if (s[i] == ' ') curState = END;
                else return false;
            } else if (curState == SIGN) {
                if (isDigit(s[i])) curState = NUM;
                else if (s[i] == '.') curState = FRAC;
                else return false;
            } else if (curState == INT) {
                if (isDigit(s[i])) continue;
                else if (s[i] == 'e') curState = EXP;
                else if (s[i] == ' ') curState = END;
                else return false;
            } else if (curState == EXP) {
                if (isDigit(s[i])) curState = DIGIT;
                else if (s[i] == '+' || s[i] == '-') curState = EXPSIGN;
                else return false;
            } else if (curState == EXPSIGN) {
                if (isDigit(s[i])) curState = DIGIT;
                else return false;
            } else if (curState == DIGIT) {
                if (isDigit(s[i])) continue;
                else if (s[i] == ' ') curState = END;
                else return false;
            } else if (curState == END) {
                if (s[i] == ' ') continue;
                else return false;
            }
        }
        if (curState == NUM || curState == DOT || curState == INT || curState == DIGIT || curState == END)
            return true;
        return false;
    }
    bool isDigit(char c) {
        if (c <= '9' && c >= '0') return true;
        return false;
    }
};
