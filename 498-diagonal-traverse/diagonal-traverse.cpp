class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>res;
        map<int,vector<int>>mp;
        for(int i=0;i<mat.size();i++){
            //every daigonal has unique val (i+j)
            for(int j=0;j<mat[0].size();j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        bool flip=true;
        for(auto &it : mp){
            if(flip){
                reverse(it.second.begin(),it.second.end());
            }
            for(auto &num : it.second){
                res.push_back(num);
            }
            flip=!flip;
        }
        return res;
    }
};