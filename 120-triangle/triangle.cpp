//easy
class Solution {
public: 
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>t=triangle;
        for(int row=n-2;row>=0;row--){  //st from sec last row
            for(int col=0;col<=row;col++){
                t[row][col]+=min(t[row+1][col],t[row+1][col+1]);
            }
        }

        return t[0][0];

        // int n=triangle.size();
        // vector<vector<int>>t(n+1,vector<int>(n+1,-1));
        // return solve(triangle,0,0,t);

    }
    // int solve(vector<vector<int>>& tri ,int i,int j,vector<vector<int>>&t){
    //     if( i >= tri.size() || j >=tri[i].size() ){
    //         return 0;
    //     }
    //     int curr;
    //     int next;
    //     if(t[i][j]!=-1){
    //         return t[i][j];
    //     }
    //     curr=tri[i][j] + solve(tri,i+1,j,t);
    //     if( j+1 <tri[i].size()){
    //         next=tri[i][j+1] +solve(tri,i+1,j+1,t);
    //     }
    //     return t[i][j]=min(curr,next);
    // }
};