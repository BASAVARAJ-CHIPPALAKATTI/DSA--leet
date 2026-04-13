class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool>visited(n,false);
        int groups=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,stones,visited);
                groups++;
            }
        }
        //actually we need to (g1+g2+g3)-1-1-1; == n-groups

        return n-groups;
    }
    void dfs(int idx,vector<vector<int>>& stones,vector<bool>&visited){

        visited[idx]=true;
        for(int i=0;i<stones.size();i++){
            int row=stones[i][0];
            int col=stones[i][1];

            if((row==stones[idx][0] || col==stones[idx][1])&& !visited[i]){
                dfs(i,stones,visited);
            }
        }
    }
};