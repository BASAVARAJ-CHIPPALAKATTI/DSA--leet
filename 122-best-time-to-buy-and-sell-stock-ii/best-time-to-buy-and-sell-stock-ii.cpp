// own 
// u buy if price high sell again buy that one 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        int min_price=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(min_price > prices[i] ){
                min_price=prices[i];
            }
            else{ //if u get high price val
                max_profit+=prices[i] - min_price;
                min_price=prices[i];
            }
        }
        return max_profit;
    }
};