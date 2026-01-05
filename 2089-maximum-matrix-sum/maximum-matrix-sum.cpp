class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int minval=INT_MAX;
        int count=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]<0){
                    count++;
                    ans+=matrix[i][j]*-1;
                    minval=min(minval,matrix[i][j]*-1);
                }
                else{
                    ans+=matrix[i][j];
                    minval=min(minval,matrix[i][j]);
                }  
            }
        }
        if(count%2==0){
            return ans;
        }
        return ans-minval*2;
    }
};