class Solution {
public:
    string countAndSay(int n) {
        string seq = "1";
        n--;
        while (n--) {
            seq = say(seq);
        }
        return seq;
    }
    
    string say(string seq) {
        string newSeq = "";
        int count = 1;
        char ch = seq[0];
        for (int i = 1; i < seq.length(); i++) {
            if (ch == seq[i]) count ++;
            else {
                char num = count + '0';
                newSeq = newSeq + num + ch;
                ch = seq[i];
                count = 1;
            }
        }
        char num = count + '0';
        newSeq = newSeq + num + ch;
        return newSeq;
    }
};
