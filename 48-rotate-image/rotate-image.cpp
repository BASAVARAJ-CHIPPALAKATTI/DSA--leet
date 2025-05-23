class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix[0].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        // for(int i=0;i<matrix.size();i++){
        //     int j=0;
        //     int k=matrix.size()-1;
        //     while(j<k){
        //         swap(matrix[i][j],matrix[i][k]);
        //         j++;
        //         k--;
        //     }
        // }

        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};