//dfs draw and understand
class Solution {
public:
    int count;
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int,vector<int>>mp;
        count=0;
        for(vector<int>edge : edges){
            int u=edge[0];
            int v=edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        dfs(mp,0,-1,values,k);
        return count;
        
    }
    int dfs(unordered_map<int,vector<int>>&mp,int curr,int parent ,vector<int>&values,int k ){
        int sum=0;
        for(int adj : mp[curr]){
            if(adj!=parent){
                sum +=dfs(mp,adj,curr,values,k);
                sum %=k;
            }
        }
        sum +=values[curr];
        sum %= k;
        if(sum==0){
            count++;
        }
        return sum;
    }
};