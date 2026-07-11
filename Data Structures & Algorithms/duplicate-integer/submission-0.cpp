class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> appeared;
        for(const auto& val: nums){
            if(appeared.find(val) != appeared.end()) return true;
            else appeared.insert(val);
        }
        return false;
    }
};