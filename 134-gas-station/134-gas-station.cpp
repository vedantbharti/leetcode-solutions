class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr_balance = 0, rem_balance = 0, index = 0;
        for(int i=0;i<cost.size();i++){
            curr_balance = curr_balance + gas[i] - cost[i];
            if(curr_balance<0){
                rem_balance = curr_balance + rem_balance;
                curr_balance = 0;
                index = i+1;
            }
        }
        
        if(curr_balance + rem_balance < 0) return -1;
        return index;
    }
};