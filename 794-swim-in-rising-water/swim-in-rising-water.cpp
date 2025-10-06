class Solution {
public:
    vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
    int swimInWater(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int low=grid[0][0];
        int high=n*n-1;
        int res;
        res=high;

        while(low<=high){  //binary serach for partiucalar time
            int mid=low+(high-low)/2;
            vector<vector<bool>>visited(n,vector<bool>(n,false));
            if(ispossible(grid,0,0,mid,visited)){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }

    bool ispossible(vector<vector<int>>& grid,int i,int j,int t,vector<vector<bool>>&visited){
        int n=grid.size();
        if(i >=n || i<0 || j >=n || j<0 || visited[i][j]==true || grid[i][j] > t){
            return false;
        }
        visited[i][j]=true;
        if(i==n-1 && j==n-1){
            return true;
        }
        for(auto d : dir){
            int i_ =i+d[0];
            int j_ =j+d[1];

            if(ispossible(grid,i_,j_,t,visited)){
                return true;
            }
        }
        return false;
    }
};