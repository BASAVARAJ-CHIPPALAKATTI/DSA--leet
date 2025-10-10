class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int>dp(n,0);
        for(int i=n-1;i>=0;i--){ //we start from rev so that it you start any point you need to move i+k if that is less than n
    
            if(i+k < n){
                dp[i]=dp[i+k]+energy[i];
            }
            else{
                dp[i]=energy[i];
            }
        }
        return  *max_element(dp.begin(),dp.end());
    }
};