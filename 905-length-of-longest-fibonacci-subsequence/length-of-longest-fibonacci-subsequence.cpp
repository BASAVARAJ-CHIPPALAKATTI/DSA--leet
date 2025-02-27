/*
think a+b=c
c-b=a

two for loop for  c, b
and recursion for finding sub fib
*/
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        vector<vector<int>>t(n,vector<int>(n,-1));
        int maxlen=0;
        for(int j=0;j<n;j++){
            for(int k=j+1;k<n;k++){
                int len=solve(j,k,arr,mp ,t);
                if(len>=3){
                    maxlen=max(maxlen,len);
                }
            }
        }
        return maxlen;
    }
    int solve(int j,int k,vector<int>&arr,unordered_map<int,int>& mp,vector<vector<int>>&t){
        if(t[j][k]!=-1) return t[j][k];
        int target=arr[k]-arr[j];
        if(mp.count(target) && mp[target]<j){
            int i=mp[target];
            return t[j][k]=solve(i,j,arr,mp,t)+1; //plus one for k
        }
        //if not match in map
        return 2; //plus two for i and j 
    }
};