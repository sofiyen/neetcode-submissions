class Solution {
public:

    string encode(vector<string>& strs) {
        string final_str = "";
        for(const auto& str: strs){
            int size = str.length();
            final_str += to_string(size);
            final_str += "#";
            final_str += str;
        }
        return final_str;
    }

    vector<string> decode(string s) {
        vector<string> final_list = {};
        size_t cur = 0;
        while(cur < s.length()){
            // 1. get the size
            size_t i = cur;
            while(s[i] != '#'){
                i++;
            }
            int size = stoi(s.substr(cur, i - cur));
            // 2. pass the "#"
            i++;
            // 3. get the str + add to vector
            string str = s.substr(i, size);
            final_list.push_back(str);
            // 4. update cur
            cur = i + size;
        }
        return final_list;
    }

};
