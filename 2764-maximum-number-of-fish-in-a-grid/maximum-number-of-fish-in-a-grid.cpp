//own
class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int maxfish=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0){
                    maxfish=max(maxfish,dfs(grid,i,j));
                }
            }
        }
        return maxfish;
    }
    int dfs(vector<vector<int>>&grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()){
            return 0;
        }
        if(grid[i][j]==0){
            return 0;
        }
        int ans=grid[i][j];
        grid[i][j]=0; // to make visited
        ans+=(dfs(grid,i+1,j)+dfs(grid,i,j+1)+dfs(grid,i-1,j)+dfs(grid,i,j-1));
        return ans;
    }
};