class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        for(auto &mat : matrix){
            vector<int>invert(m);
            for(int i=0;i<m;i++){
                invert[i]=mat[i]==0?1:0;
            }
            int currans=0;
            for(auto &curr : matrix){
                if(curr==mat || curr==invert){
                    currans++;
                }
            }
            ans=max(ans,currans);
        }
        return ans;
    }
};