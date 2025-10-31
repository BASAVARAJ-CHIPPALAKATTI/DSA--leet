class Solution {
public:
    int M=1e9 + 7;
    int m;
    int n;
    vector<vector<vector<int>>>t ;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m=m;
        this->n=n;
        t = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return solve(maxMove,startRow,startColumn);
    }
    int solve(int maxmove,int i,int j){
        if(i>=m|| j>=n|| i < 0||j<0){
            return 1;
        }
        if(maxmove <=0){
            return 0;
        }
        if(t[i][j][maxmove]!=-1){
            return t[i][j][maxmove];
        }
        long paths = 0;
        paths = (paths + solve(maxmove - 1, i + 1, j)) % M;
        paths = (paths + solve(maxmove - 1, i, j + 1)) % M;
        paths = (paths + solve(maxmove - 1, i - 1, j)) % M;
        paths = (paths + solve(maxmove - 1, i, j - 1)) % M;
        
        return t[i][j][maxmove] = paths;
    }
};