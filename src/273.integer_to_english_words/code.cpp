class Solution {
private:
    string word1[11] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"};
    string word2[9] = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string word3[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string word4[4] = {"Hundred", "Thousand", "Million", "Billion"};
public:
    string numberToWords(int num) {
        string ans;
        if (num == 0) return word1[0];
        if (num / 1000000000 > 0) {
            ans = ans + hundredToWords(num / 1000000000) + " " + word4[3];
            num %= 1000000000;
        }
        if (num / 1000000 > 0) {
            ans = ans + hundredToWords(num / 1000000) + " " + word4[2];
            num %= 1000000;
        }
        if (num / 1000 > 0) {
            ans = ans + hundredToWords(num / 1000) + " " + word4[1];
            num %= 1000;
        }
        if (num > 0) {
            ans = ans + hundredToWords(num);
        }
        return ans.substr(1, ans.length() - 1);
    }
    string hundredToWords(int num) {
        string ans;
        if (num / 100 > 0) {
            ans = ans + " " + word1[num / 100] + " " + word4[0]; 
        }
        num %= 100;
        if (num == 0) return ans;
        else if (num <= 10) ans = ans + " " + word1[num];
        else if (num < 20) ans = ans + " " + word2[num - 11];
        else {
            ans = ans + " " + word3[num / 10 - 2];
            if (num % 10 != 0) ans = ans + " " + word1[num % 10];
        }
        return ans;
    }
};
