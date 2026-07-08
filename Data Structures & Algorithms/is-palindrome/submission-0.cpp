class Solution {
public:
    bool isPalindrome(string s) {
        int head = 0;
        int toe = s.size() - 1;

        while(head < toe){
            char head_c = tolower(s[head]);
            char toe_c = tolower(s[toe]);

            if(!alphanumeric(head_c)) head++;
            else if(!alphanumeric(toe_c)) toe--;
            else if (head_c != toe_c) return false;
            else {
                head++;
                toe--;
            }
        }
        return true;
    }

    bool alphanumeric(char c){
        return ('a' <= c && c <= 'z') || ('0' <= c && c <= '9');
    }
};
