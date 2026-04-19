class Solution(object):
    def isValidSudoku(self, board):
        st=set()
        for i in range(9):
            for j in range(9):
                if board[i][j]=='.':
                    continue
                row=str(board[i][j])+"row"+str(i)
                col=str(board[i][j])+"col"+str(j)
                box=str(board[i][j])+"box"+str(i//3)+str(j//3)

                if row in st or col in st or box in st:
                    return False
                else:
                    st.add(row)
                    st.add(col)
                    st.add(box)
        return True