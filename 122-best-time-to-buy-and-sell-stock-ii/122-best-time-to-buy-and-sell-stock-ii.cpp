class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int start = 0;
        int ans = 0;
        for(int i=1;i<n;i++){
            if(prices[i]<prices[i-1]){
                ans += prices[i-1] - prices[start];
                start = i;
            }
            
            if(i==n-1){
                if(prices[i]>=prices[i-1]){
                    ans += prices[i] - prices[start];
                }
            }
        }
        
        return ans;
    }
};