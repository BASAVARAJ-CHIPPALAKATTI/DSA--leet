class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans=0;
        for(auto q: queries){
            int l=q[0];
            int r=q[1];
            long long steps=solve(l,r);
            ans+=(steps+1)/2;  // in pair we need to do floor operation 
        }
        return ans;
    }
    long long solve(int l,int r){
        long long L=1;
        long long S=1;
        long long step=0;
        while(L<=r){
            long long R=L*4-1;
            long long start=max(L,(long long)l);
            long long end=min(R,(long long)r);
            if(start <= end){
                step+=(end-start+1)*S;
            }
            S++;
            L=L*4;
        }
        return step;
    }
};