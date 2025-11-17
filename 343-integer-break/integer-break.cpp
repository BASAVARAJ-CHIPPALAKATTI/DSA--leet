class Solution {
public:
    int t[59];
    int integerBreak(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }
    int solve(int n){
        if(n ==0){
            return 0;
        }
        if(t[n]!=-1){
            return t[n];
        }
        int ans=(n-1);   //n-1 * 1 ==n-1 
        for(int i=1;i<n-1;i++){
            int pro=i*(max(n-i,  solve(n-i)));

            ans=max(pro,ans);
        }
        return t[n]=ans;
    }

};