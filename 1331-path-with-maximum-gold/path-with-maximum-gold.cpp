class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    ans=max(ans,solve(grid,i,j));
                }
            }
        }
        return ans;
    }
    int solve(vector<vector<int>>&grid,int i, int j){
        if( i<0 ||i>= grid.size() || j<0 ||j >=grid[0].size()){
            return 0;
        }
        if(grid[i][j]==0){
            return 0;
        }
        int val=grid[i][j];
        grid[i][j]=0;
        int ans=val+max({solve(grid,i+1,j),solve(grid,i,j+1),solve(grid,i-1,j),solve(grid,i,j-1)});
        grid[i][j]=val;
        return ans;
    }
};