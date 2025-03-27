//own
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>visited(rooms.size(),false);
        dfs(rooms,visited,0);
        for(int i=0;i<visited.size();i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
    void dfs(vector<vector<int>>& rooms , vector<bool>&visited,int idx){
        visited[idx]=true;
        for(int i=0;i<rooms[idx].size();i++){
            int val=rooms[idx][i];
            if(!visited[val]){
                dfs(rooms,visited,val);
            }
        }
    }
};