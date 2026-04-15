class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(n,false);
        visited[0]=true;
        dfs(rooms,0,visited);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
    void dfs(vector<vector<int>>& rooms,int i,vector<bool>&visited){
        for(int idx:rooms[i]){
            if(!visited[idx]){
                visited[idx]=true;
                dfs(rooms,idx,visited);
            }
        }
    }

};