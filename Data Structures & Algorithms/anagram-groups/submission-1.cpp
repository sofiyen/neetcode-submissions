class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, int> mp; // map pattern to id in return vector

        for(const auto& s: strs){
            // 1. Get number of unique character appearances
            vector<int> char_num(26,0); 
            for(const auto& c: s){
                int id = c - 'a';
                char_num[id]++;
            }
            string char_num_str = vecToString(char_num);
            // debug
            cout << "char_num_str = " << char_num_str << endl;
            // 2. Check if this pattern already exist: store else init
            if(mp.count(char_num_str)){
                // exist already
                int id = mp[char_num_str];
                ret[id].push_back(s);
            } else {
                // DNE yet
                vector<string> tmp;
                tmp.push_back(s);
                ret.push_back(tmp);
                // update mp
                mp[char_num_str] = ret.size()-1;
            }
        }
        return ret;
    }

    string vecToString(vector<int> arr){
        // use '#' to seperate numbers
        string ret = "";
        for(const auto& i: arr){
            ret += to_string(i);
            ret += "#";
        }
        return ret;
    }
};
