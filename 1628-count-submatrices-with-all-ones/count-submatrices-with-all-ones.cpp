class Solution {
public:
    int findrect(vector<int>&vec){
        int curr=0;
        int res=0;
        for(int i=0;i<vec.size();i++){
            if(vec[i]==0){
                curr=0;
            }
            else{
                curr++;
            }
            res+=curr;
        }
        return res;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int res=0;
        for(int startrow=0;startrow<m;startrow++){
            vector<int>colvec(n,1);
            for(int endrow=startrow;endrow<m;endrow++){
                for(int col=0;col<n;col++){
                    colvec[col]=colvec[col] & mat[endrow][col];
                }
                res+=findrect(colvec);
            }
        }
        return res;
    }
};