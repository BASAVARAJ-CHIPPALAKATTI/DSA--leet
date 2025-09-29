//checing of all possibilities
class Solution {
public:
    
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>t(51,vector<int>(51,-1));
        return solve(values,0,n-1,t);
    }
    int solve(vector<int>&values,int i,int j,vector<vector<int>>&t){
        if(j-i+1 < 3){
            return 0; //we can't make the triangle
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int res=INT_MAX;
        for(int k=i+1;k<j;k++){
            int currans=(values[i]*values[j]*values[k] + solve(values,i,k,t)+solve(values,k,j,t));
            res=min(res,currans);

        }
        return t[i][j]=res;
    }
};