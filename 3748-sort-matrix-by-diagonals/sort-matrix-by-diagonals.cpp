//easy tow approach
//one is simple traverse
//sec using map;
class Solution {
public:
    void solve(int row,int col,vector<vector<int>>& grid,bool ascend){
        int n=grid.size();
        int i=row;
        int j=col;
        vector<int>vec;
        while(i<n && j<n){
            vec.push_back(grid[i][j]);
            i++;
            j++;
        }
        if(ascend){
            sort(vec.begin(),vec.end());
        }
        else{
            sort(vec.begin(),vec.end(),greater<int>());
        }
        i=row;
        j=col;
        for(int val : vec){
            grid[i++][j++]=val;
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int row=0;row<n;row++){
            solve(row,0,grid,false);
        }
        for(int col=1;col<n;col++){
            solve(0,col,grid,true);
        }
        return grid;
    }
    
};
// class Solution {
// public:
//     vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
//         int n = grid.size();

//         unordered_map<int, vector<int>> mp;
//         //(i-j) -> diagonal elements

//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < n; j++) {
//                 int diag = i-j;
//                 mp[diag].push_back(grid[i][j]);       
//             }
//         }

//         for(auto &it : mp) {
//             if(it.first >= 0) { //Key
//                 sort(begin(it.second), end(it.second));
//             } else {
//                 sort(rbegin(it.second), rend(it.second));
//             }
//         }

//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < n; j++) {
//                 int diag = i-j;
//                 grid[i][j] = mp[diag].back();
//                 mp[diag].pop_back();      
//             }
//         }

//         return grid;
//     }
// };