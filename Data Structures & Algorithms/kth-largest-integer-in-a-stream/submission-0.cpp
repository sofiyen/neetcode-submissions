class KthLargest {
private:
    int k_val;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        k_val = k;
        for(const auto& val: nums){
            minHeap.push(val);
            if(minHeap.size() > k_val) minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k_val) minHeap.pop();
        return minHeap.top(); 
    }
};
