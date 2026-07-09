class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = 0;
        int max = 0;
        while(i < prices.size()){
            while(i+1 < prices.size() && prices[i] > prices[i+1]) i++;
            j = i + 1;
            while(j < prices.size() && prices[j] >= prices[i]){
                if(prices[j] - prices[i] > max){
                    max = prices[j] - prices[i];
                }
                j++;
            }
            // prices[j] < prices[i]
            i = j; 
        }

        return max;
    }
};


