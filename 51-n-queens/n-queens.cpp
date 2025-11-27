class Solution {
public:
    vector<vector<string>>ans; // to store all answers

    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.')); //to store single ans
        solve( board , 0 , n);
        return ans;
    }
    void solve( vector<string>board,int row , int n){
        if(row==n){  // if every row completes
            ans.push_back({board});
            return ;
        }
        for(int j=0;j<n;j++){  // try to place in diff col
            if(issafe(board,row,j,n)){
                board[row][j]='Q';
                solve(board,row+1,n); // for next row
                board[row][j]='.'; // backtrack
            }
        }
    }
    bool issafe(vector<string>board,int row,int col, int n){
        // we need to check only upper part
        // bcz we coming from upper part 

        // for horizontal
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }

        //for vertical
        for(int j=0;j<col;j++){
            if(board[row][j]=='Q'){
                return false;
            }
        }

        //for upper left daigonal
        for(int i=row-1,j=col-1 ; i>=0&& j>=0; i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }

        //for upper right daigonal
        for(int i=row-1,j=col+1 ; i>=0 && j<n ;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
};