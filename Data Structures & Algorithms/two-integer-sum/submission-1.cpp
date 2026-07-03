class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       // 1. Sort the vector: O(nlogn)
       vector<pair<int, int>> sorted;

       for(int i = 0; i < nums.size(); i++){
            sorted.push_back({nums[i], i});
       }
        
        sort(sorted.begin(), sorted.end());

       // 2. Trace through: O(n)
       int left = 0;
       int right = sorted.size() - 1;
       while(left < right){
            while((left < right) && (sorted[left].first + sorted[right].first > target)) right--;
            if(sorted[left].first + sorted[right].first == target){
                if(sorted[left].second < sorted[right].second){
                    return {sorted[left].second, sorted[right].second};
                }else{
                    return {sorted[right].second, sorted[left].second};
                }
            } else left++;
       }
    }
};
