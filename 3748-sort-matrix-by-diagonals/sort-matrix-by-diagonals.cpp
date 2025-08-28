//easy tow approach
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        //bottom left side 
        //col is fix
        for(int row=0;row<m;row++){
            solve(row,0,grid,false);  //true means ascending
        }
        for(int col=1;col<m;col++){
            solve(0,col,grid,true);
        }
        return grid;
    }

    void solve(int row,int col,vector<vector<int>>&grid,bool ascend){
        vector<int>vec;
        int i=row;
        int j=col;
        while(row <grid.size() && col <grid.size()){
            vec.push_back(grid[row][col]);
            row++;
            col++;
        }
        if(ascend){
            sort(vec.begin(),vec.end());
        }
        else{
            sort(vec.rbegin(),vec.rend()); //decending
        }
        for(int a=0;a<vec.size();a++){
            grid[i++][j++]=vec[a];
        }
    }
};