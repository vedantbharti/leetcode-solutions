class Solution {
    
//greedy solution proof:
//suppose a,b,c,d are 4 numbers such that a<b,b>c,b<d
//prove that d-a<(b-a)+(d-c)
//rearranging the RHS, we can write (b-a)+(d-c) = (d-a)+(b-c) > d-a
//since b-c is greater than 0
//Hence greedy solution works  
    
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