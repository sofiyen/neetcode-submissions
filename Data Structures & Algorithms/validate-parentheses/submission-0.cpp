class Solution {
public:
    bool isValid(string s) {
        stack<char> s_1, s_2;

        // 1. Fill s_1
        for(const auto& c: s){
            s_1.push(c);
        }

        // 2. Repeat the matching
        while(!s_1.empty()){
            char top_1 = s_1.top();
            s_1.pop();
            if(!s_2.empty() && match(top_1, s_2.top())){
                // pop s_2 when match
                s_2.pop();
            } else {
                s_2.push(top_1);
            }
        }

        return s_2.empty();
    }

    bool match(char a, char b){
        return ((a == '[' && b == ']') || 
            (a == '(' && b == ')') ||
            (a == '{' && b == '}'));
    }
};
