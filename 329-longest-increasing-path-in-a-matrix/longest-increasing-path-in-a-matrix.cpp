class Solution {
public:
    vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
    int t[201][201];
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(t,-1,sizeof(t));
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans=max(ans,dfs(i,j,matrix));
            }
        }
        return ans;
    }
    int dfs(int i,int j,vector<vector<int>>& matrix){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size()){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int curr=1;
        for(auto d : dir){
            int x=d[0]+i;
            int y=d[1]+j;
            if(x<0 || y<0 || x>=matrix.size() || y>=matrix[0].size()){
                continue;
            }
            if(matrix[i][j] < matrix[x][y]){
                curr=max(curr,1+dfs(x,y,matrix));
            }
        }
        return t[i][j]=curr;
    }
};