class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;

        // 1. count for each unique value
        unordered_map<int, int> count;
        int max_count = 0;
        for(const auto& val: nums){
            count[val]++; // already init as 0
            if (count[val] > max_count) max_count = count[val];
        }

        // 2. Bucket Sort by count.second (numbers)
        vector<vector<int>> bucket(max_count + 1); // count -> list of val
        for(const auto& p: count){
            int c = p.second;
            int v = p.first;
            bucket[c].push_back(v);
        }

        // 3. Return the top k elements from bucket
        int select = k;
        int cur = max_count;
        while(cur >= 0 && select > 0){
            vector<int> cur_val = bucket[cur];
            if(cur_val.size()){ // not empty
                for(const auto& c: cur_val){
                    ret.push_back(c);
                    select--;
                }
            }
            cur--;
        }

        return ret;
    }
};