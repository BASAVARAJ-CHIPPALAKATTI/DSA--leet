/*
think a+b=c
c-b=a
*/
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        int maxlen=0;
        for(int j=0;j<n;j++){
            for(int k=j+1;k<n;k++){
                int len=solve(j,k,arr,mp);
                if(len>=3){
                    maxlen=max(maxlen,len);
                }
            }
        }
        return maxlen;
    }
    int solve(int j,int k,vector<int>&arr,unordered_map<int,int>& mp){
        int target=arr[k]-arr[j];
        if(mp.count(target) && mp[target]<j){
            int i=mp[target];
            return solve(i,j,arr,mp)+1; //plus one for k
        }
        //if not match in map
        return 2; //plus two for i and j 
    }
};