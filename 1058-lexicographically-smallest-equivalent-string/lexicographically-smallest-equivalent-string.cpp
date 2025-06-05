//revision
//easy level graph
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        
        unordered_map<char,vector<char>>adj_list;
        for(int i=0;i<n;i++){
            char u=s1[i];
            char v=s2[i];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        string ans="";
        for(int i=0;i<baseStr.size();i++){
            // for every char call dfs to get minchar
            char c=baseStr[i];
            vector<int>visited(26,0);
            char minchar=dfs_of_minchar(c,adj_list,visited);
            ans.push_back(minchar);
        }
        return ans;
    }
    char dfs_of_minchar(char currchar,unordered_map<char,vector<char>>adj_list,vector<int>&visited){
        visited[currchar-'a']=1;
        char minchar=currchar;
        for(char c : adj_list[currchar]){
            if(visited[c-'a']==0){
                minchar=min(minchar,dfs_of_minchar(c,adj_list,visited));
            }
        }
        return minchar;
    }
};