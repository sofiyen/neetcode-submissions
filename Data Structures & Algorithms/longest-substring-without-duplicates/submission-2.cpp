class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_map<char, int> appear; // character, id
        int start = 0;
        int end = start;
        int max = 0;
        int i = 0;

        for(const auto& c: s){
            if(appear.count(c) > 0){ /* DUP */

                // update max
                int len = end - start + 1;
                if (len > max) max = len;

                // update start pointer
                int last = appear[c];
                start = last + 1;

                // remove all characters with id <= last
                unordered_map<char, int> tmp;
                for(const auto& p: appear){
                    if(p.second > last){
                        tmp[p.first] = p.second;
                    }
                }
                appear = tmp;
            } 
            // add current to map
            appear[c] = i;
            // update end pointer
            end = i;

            i++;
        }
        if(end - start + 1 > max) max = end - start + 1;
        return max;
    }
};
