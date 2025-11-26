class Solution {
public:
    int M = 1e9+7;
    vector<vector<vector<int>>> t;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        t.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return solve(grid,k,0,0,0);
    }
    int solve(vector<vector<int>>& grid,int k,int i,int j,int sum){
        if(i >= grid.size() || j >= grid[0].size()){
            return 0;
        }
        if(i==grid.size()-1 && j==grid[0].size()-1){
            if((sum+grid[i][j]) % k==0){
                return 1;
            }
            return 0;
        }
        sum = (sum+grid[i][j]) % k;
        if(t[i][j][sum]!=-1){
            return t[i][j][sum];
        }
        int ans=0;
        
        ans=(ans+solve(grid,k,i+1,j,sum))%M ;
        ans=(ans+solve(grid,k,i,j+1,sum))%M;
        
        return t[i][j][sum]=  ans;
    }
};