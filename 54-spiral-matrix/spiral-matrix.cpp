class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int top=0;
        int down=matrix.size()-1; //rows
        int left=0;
        int right=matrix[0].size()-1; //cols

        int id=0;
        while(top<=down && left<=right){
            if(id==0){
                for(int i=left;i<=right;i++){
                    res.push_back(matrix[top][i]);
                }
                top++;
                
            }
            if(id==1){
                for(int i=top;i<=down;i++){
                    res.push_back(matrix[i][right]);
                }
                right--;
                
            }
            if(id==2){
                for(int i=right;i>=left;i--){
                    res.push_back(matrix[down][i]);
                }
                down--;
                
            }
            if(id==3){
                for(int i=down;i>=top;i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
                
            }
            id=(id+1)%4;
        }
        return res;
    }
};