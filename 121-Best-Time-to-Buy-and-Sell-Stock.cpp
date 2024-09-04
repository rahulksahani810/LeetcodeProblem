class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX;
        int maxDiff = 0 ;
        for(int i=0;i<prices.size();i++){
            if(prices[i] < minVal){
                minVal = prices[i];
            
            }
            if((prices[i]-minVal) > maxDiff){
                maxDiff = prices[i]-minVal;
            }
        }
        return maxDiff;

        
    }
};