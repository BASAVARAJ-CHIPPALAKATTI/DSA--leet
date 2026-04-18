//easy
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int total_min=0;
        int minval=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]<0 ){
                    total_min=(total_min+1) % 2;
                }
                int val=abs(matrix[i][j]);
                ans+=val;
                minval=min(minval,val);
            }
        }
        if(total_min % 2==0){
            return ans;
        }
        return ans-(minval*2);
    }
};