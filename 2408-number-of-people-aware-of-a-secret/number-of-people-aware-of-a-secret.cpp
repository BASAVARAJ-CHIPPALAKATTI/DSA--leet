//revision
class Solution {
public: int M= 1e9+7;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        int res=0;
        //how many people know secret last day
        //secret tell by 
        //n-forget+1;
        vector<int>t(n+1,-1);
        for(int day=n-forget+1;day<=n;day++){
            if(day >0){
                res=(res+solve(day,delay,forget,t))%M;
            }
        }
        return res;
    }
    int solve(int day,int delay,int forget,vector<int>&t){
        if(day==1){
            return 1;
        }
        if(day <=0 ){
            return 0;
        }
        if(t[day]!=-1){
            return t[day];
        }
        int ans=0;
        for(int prev=day-forget+1;prev<=day-delay;prev++){
            if(prev >0){
               ans=(ans+solve(prev,delay,forget,t))%M;
            }
        }
        return t[day]=ans;
    }
};