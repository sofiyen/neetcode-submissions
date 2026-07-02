class Solution {
public:
    vector<int> str_sizes = {};

    string encode(vector<string>& strs) { // list of strings -> a string
        /*
        1. needs to store size of each str for decode.
        2. needs to support ["", "", ""]
        */

        string a_string = "";
        for(const auto& str: strs){ // use const to read without copying
            str_sizes.push_back(str.length());
            a_string += str;
        }
        cout << a_string << endl;
        return a_string;
    }

    vector<string> decode(string s) { // a string -> list of strings
        vector<string> strs = {};
        size_t cur_id = 0; // current index in str_sizes
        for(const auto& str_size: str_sizes){
            string str = s.substr(cur_id, str_size);
            cout << str << endl;
            strs.push_back(str);
            cur_id += str_size;
        }
        return strs;
    }
};
