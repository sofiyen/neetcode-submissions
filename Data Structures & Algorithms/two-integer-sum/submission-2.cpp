class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
    
        for(int i = 0; i < nums.size(); i++){
            int require = target - nums[i];
            if(mp.count(require)){ // hit
                return {mp[require], i};
            } else { // miss -> store i if nums[i] not in mp
                if (!(mp.count(nums[i]))){
                    mp[nums[i]] = i;
                }
            }
        }
    }
};
