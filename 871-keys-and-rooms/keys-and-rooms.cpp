//own
class Solution {
public:
    bool visited[1001];
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        memset(visited,false,sizeof(visited));
        dfs(rooms,0);
        for(int i=0;i<rooms.size();i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;
    }
    void dfs(vector<vector<int>>& rooms,int i){
        if(visited[i]){
            return ;
        }
        visited[i]=true;
        for(int j:rooms[i]){
            dfs(rooms,j);
        }
    }
};