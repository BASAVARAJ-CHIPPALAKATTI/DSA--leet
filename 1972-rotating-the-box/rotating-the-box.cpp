class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        for(int i=0;i<boxGrid.size();i++){
            int k=boxGrid[0].size()-1;
            for(int j=boxGrid[0].size()-1;j>=0;j--){
                if(boxGrid[i][j]=='#'){
                    boxGrid[i][j]='.';
                    boxGrid[i][k]='#';
                    k--;
                }
                if(boxGrid[i][j]=='*'){
                    k=j-1;
                }
            }
        }
        //rotate 90 degree
        int m=boxGrid.size();
        int n=boxGrid[0].size();
        vector<vector<char>>ans(n,vector<char>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[j][i]=boxGrid[i][j];
            }
        }
        for(vector<char>&row:ans){
            reverse(row.begin(),row.end());
        }
        return ans;
    }
};