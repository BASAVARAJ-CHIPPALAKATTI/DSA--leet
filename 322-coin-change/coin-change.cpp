class Solution {
public:
    int t[13][10001];
    int coinChange(vector<int>& coins, int amount) {
        memset(t,-1,sizeof(t));
        int ans=solve(coins,amount,0);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
    int solve(vector<int>&coins,int amount,int i){
        if(amount==0){
            return 0;
        }
        if(i>=coins.size() || amount <0){
            return INT_MAX;
        }
        if(t[i][amount]!=-1){
            return t[i][amount];
        }
        int pick=solve(coins,amount-coins[i],i);
        if(pick!=INT_MAX){
            pick+=1;
        }
        int notpick=solve(coins,amount,i+1);

        return t[i][amount] =min(pick,notpick);
    }
};