class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>zeors_row(n,0);
        for(int i=0;i<n;i++){
             int j=grid[0].size()-1;
             int count=0;
             while(j >=0 && grid[i][j]==0){
                j--;
                count++;
             }
             zeors_row[i]=count;
        }
        int res=0;
        for(int i=0;i<n;i++){
            int need = n-i-1;
            int j=i;
            while(j < n && zeors_row[j] < need){
                j++;
            }
            if(j==n){
                return -1;
            }
            res+=j-i;
            //swap it
            while( j > i){
                swap(zeors_row[j],zeors_row[j-1]);
                j--;
            }
        }
        return res;
    }
};