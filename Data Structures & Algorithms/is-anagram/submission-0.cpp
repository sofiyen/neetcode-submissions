class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        // map for s
        unordered_map<char, int> s_mp;
        // map for t
        unordered_map<char, int> t_mp;

        // 1. Count chars in strings
        for(const auto& s_char: s){
            if (s_mp.count(s_char)) {
                s_mp[s_char]++;
            } else {
                s_mp[s_char] = 1;
            }
        }

        for(const auto& t_char: t){
            if (t_mp.count(t_char)) {
                t_mp[t_char]++;
            } else {
                t_mp[t_char] = 1;
            }
        }

        // 2. Compare 
        for(const auto& s_pair: s_mp){
            char unique_c = s_pair.first;
            int times = s_pair.second;

            if(t_mp.count(unique_c) == 0 || t_mp[unique_c] != times) return false;
        }

        return true;
    }
};
