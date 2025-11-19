class Solution {
public: 
    int dp[10001];
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(coins,amount);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
    int solve(vector<int>& coins, int amount){
        if(amount ==0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int ans=INT_MAX;
        for(int coin : coins){
            int res=solve(coins,amount-coin);
            if(res!=INT_MAX){
                ans=min(ans,1+res);
            }
        }
        return dp[amount] = ans;
    }
};