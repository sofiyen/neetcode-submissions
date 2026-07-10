class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;

        unordered_map<char, int> lastSeen;
        int start = 0, end = 0;
        int max = 1;
        int i = 0;

        for(const auto& c: s){
            /* DUP */
            if(lastSeen.count(c) && lastSeen[c] >= start){
                // update max
                if(end - start + 1 > max) max = end - start + 1;
                // update start pointer
                start = lastSeen[c] + 1;
            }
            // update lastSeen 
            lastSeen[c] = i;
            // update end pointer
            end = i;
            i++;
        }
        // update max
        if(end - start + 1 > max) max = end - start + 1;
        return max;
    }
};
