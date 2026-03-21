class Solution {
public:
    int t[201][201];
    int minPathSum(vector<vector<int>>& grid) {
        memset(t,-1,sizeof(t));
        return solve(grid,0,0);
    }
    int solve(vector<vector<int>>&grid,int i,int j){
        if(i>=grid.size() || j>=grid[0].size()){
            return 99999;
        }
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[i][j];
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int left=grid[i][j]+ solve(grid,i,j+1);
        int bottom=grid[i][j]+ solve(grid,i+1,j);

        return t[i][j]= min(left,bottom);
    }
};