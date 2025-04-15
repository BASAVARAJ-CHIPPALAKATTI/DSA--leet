class Solution {
public:
//    int m,n;
//    int t[1001][1001];
//     int longestCommonSubsequence(string text1, string text2) {
//         m=text1.size();
//         n=text2.size();
//         memset(t,-1,sizeof(t));
//         return solve(text1,text2,0,0);
//     }
//     int solve(string s1,string s2,int i,int j){
//         if(i>=m || j>=n){
//             return 0;
//         }
//         if(t[i][j]!=-1){
//             return t[i][j];
//         }
//         if(s1[i]==s2[j]){
//             return t[i][j]= 1+solve(s1,s2,i+1,j+1); // if both are match and we need to move both
//         }
//         // if not match we go for skip curr i and j
//         return t[i][j]= max(solve(s1,s2,i+1,j),solve(s1,s2,i,j+1));
//     }
//tle

// bottom to up
//https://www.youtube.com/watch?v=aJNu_DLyOxY
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>t(m+1,vector<int>(n+1));

        for(int row=0;row<m;row++){
            t[row][0]=0;
        }
        for(int col=0;col<n;col++){
            t[0][col]=0;
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(text1[i-1]==text2[j-1]){
                    t[i][j]=t[i-1][j-1]+1;
                }
                else{
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
                }
            }
        }
        return t[m][n];
    }
};