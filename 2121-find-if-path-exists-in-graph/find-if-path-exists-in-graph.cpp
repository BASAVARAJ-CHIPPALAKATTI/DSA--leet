class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>mp;
        vector<bool>visited(n,false);
        visited[source]=true;
        for(auto edge : edges){
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }
        return dfs(mp,visited,source,destination);
    }
    bool dfs(unordered_map<int,vector<int>>&mp,vector<bool>&visited,int source, int destination){
        if(source==destination){
            return true;
        }
        for(int next : mp[source]){
            if(!visited[next]){
                visited[next]=true;
                if(dfs(mp,visited,next,destination)){
                    return true;
                }
            }
        }
        return false;
    }
};