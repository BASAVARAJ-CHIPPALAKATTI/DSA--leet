class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //1st approach
        //traverse row and col and 3*3 matrix if duplicate present return false
        //else return true

        //for row
        for(int row=0;row<9;row++){
            unordered_set<char>st;
            for(int col=0;col<9;col++){
                char val=board[row][col];
                if(val=='.'){
                    continue;
                }
                if(st.count(val)){
                    return false;
                }
                st.insert(val);
            }
        }
        //for col
        for(int col=0;col<9;col++){
            unordered_set<char>st;
            for(int row=0;row<9;row++){
                char val=board[row][col];
                if(val=='.'){
                    continue;
                }
                if(st.count(val)){
                    return false;
                }
                st.insert(val);
            }
        }
        //for 3*3 matrix
        for(int row = 0; row < 9; row += 3) {
            for(int col = 0; col < 9; col += 3) {
                if(!check_valid(board, row, row + 2, col, col + 2)) {
                    return false;
                }
            }
        }
        return true;
    }
    bool check_valid(vector<vector<char>>&board,int sr,int er, int sc,int ec){
        unordered_set<char>st;
        for(int row=sr;row<=er;row++){
            for(int col=sc;col<=ec;col++){
                char val=board[row][col];
                if(val=='.'){
                    continue;
                }
                if(st.count(val)){
                    return false;
                }
                st.insert(val);
            }
        }
        return true;
    }

};