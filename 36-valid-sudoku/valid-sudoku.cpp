class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //1st approach
        //traverse row and col and 3*3 matrix if duplicate present return false
        //else return true

        //for row
        /*for(int row=0;row<9;row++){
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
        */

        //string(n, char) is a C++ constructor that creates a string consisting of n copies of the character char
        //2nd approach
        unordered_set<string>st;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    continue;
                }
 //string(n, char) is a C++ constructor that creates a string consisting of n copies of the character char
                    string row=string(1,board[i][j]) + "_row_" +to_string(i);  //for row
                    string col=string(1,board[i][j]) + "_col_" +to_string(j);  //for col
                    string box=string(1,board[i][j]) + "_box_" +to_string(i/3)+to_string(j/3); //for box
                    if(st.count(row)|| st.count(col) || st.count(box)){
                        return false;
                    }
                    st.insert(row);
                    st.insert(col);
                    st.insert(box);
                
            }
        }
        return true;
    }

};