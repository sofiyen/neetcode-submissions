class Solution {
public:
    int climbStairs(int n) {
        vector<int> stairs(n+1);
        stairs[0] = 0;
        for(int i = 1; i <= n; i++){
            if(i == 1 || i == 2) stairs[i] = i;
            else stairs[i] = stairs[i-1] + stairs[i-2];
        }
        return stairs[n];
    }
};
