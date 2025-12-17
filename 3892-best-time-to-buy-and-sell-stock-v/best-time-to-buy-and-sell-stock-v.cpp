class Solution {
public:
    long long t[1001][501][3];
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<=k;j++){
                for(int k=0;k<3;k++){
                    t[i][j][k]=INT_MIN;
                }
            }
        }
        return solve(prices, k, 0, 0);
    }
    long long solve(vector<int>& prices, int k, int i, int Case) {
        if (i >= prices.size()) {
            if (Case == 0) {
                return 0;
            }
            // in complete transaction
            return INT_MIN;
        }
        if(t[i][k][Case]!=INT_MIN){
            return t[i][k][Case];
        }
        long long take = 0;
        long long not_take = 0;
        
        not_take = solve(prices, k, i + 1, Case);
        if (k > 0) {
            if (Case == 1) {
                // sell
                take = prices[i] + solve(prices, k-1, i + 1, 0);

            } else if (Case == 2) {
                // future buy
                take = -prices[i] + solve(prices, k-1, i + 1, 0);

                
            } else { // buy or short_term_buy
                // buy
                take = max(-prices[i] + solve(prices, k, i + 1, 1),
                           prices[i] + solve(prices, k , i + 1, 2));
            }
        }
        return t[i][k][Case] =max(take, not_take);
    }
};