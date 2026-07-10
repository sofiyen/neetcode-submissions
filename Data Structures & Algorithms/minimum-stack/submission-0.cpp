class MinStack {
private:
    vector<pair<int, int>> stk; // <val, min>

public:
    MinStack() {
    }
    
    void push(int val) {
        // the reture value of stk.size() is unsigned!
        // this is not safe if stk is empty: int last_id = stk.size()-1;
        // just use stk.empty() to check if a vector is empty

        int cur_min;

        if (!stk.empty()){
            cur_min = stk[stk.size()-1].second;
        } else {
            // stack is empty
            cur_min = val;
        }
        
        if(val < cur_min) cur_min = val;

        stk.push_back({val, cur_min});
        return;
    }
    
    void pop() {
        stk.pop_back();
        return;
    }
    
    int top() {
        // return the value of the last node
        return stk[stk.size()-1].first;
    }
    
    int getMin() {
        // return the min of the last node
        return stk[stk.size()-1].second;
    }
};
