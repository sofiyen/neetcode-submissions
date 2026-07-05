class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // val : number
        for(const auto& val: nums){
            if(mp.count(val)) { // already exist
                mp[val]++;
            } else {
                mp[val] = 1;
            }
        }
        // sort by number of appearance
        vector<pair<int, int>> mp_pair;
        for(const auto& p: mp){
            mp_pair.push_back({p.first, p.second});
        }
        sort(mp_pair.begin(), mp_pair.end(), [](const auto& a, const auto& b){
            return a.second > b.second;
        });

        vector<int> ret;
        for(int i = 0; i < k; i++){
            int val = mp_pair[i].first;
            ret.push_back(val);
        }
        return ret;
    }
};
