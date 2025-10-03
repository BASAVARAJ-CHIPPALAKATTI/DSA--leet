class Solution {
public:
// think collecting the max value from 4 side in that min val is water range we can fill to the current box under
    typedef pair<int,pair<int,int>>pp;
    vector<vector<int>>dir={ {1,0},{0,1},{0,-1},{-1,0} };

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
        priority_queue< pp ,vector<pp>,greater<> >boundry_cell; //min heap

        //we need to push boundries to min heap 
        vector<vector<bool>>visited(m ,vector<bool>(n,false));

        for(int row=0;row<m;row++){
            for(int col : {0, n-1}){ //only for first and last col(left ,right boundry)
                boundry_cell.push({heightMap[row][col] ,{row,col}});
                visited[row][col]=true;
            }
        }
        for(int col=0;col<n;col++){
            for(int row: {0, m-1}){ //only for first and last row(top ,bottom boundry)
                boundry_cell.push({heightMap[row][col] ,{row,col}});
                visited[row][col]=true;
            }
        }
        int water=0;
        while(boundry_cell.size()){
            auto [ height,cell]= boundry_cell.top();
            boundry_cell.pop();

            int r=cell.first;
            int c=cell.second;

            for(auto d : dir){
                int i_=r+d[0];
                int j_=c+d[1];

                if(i_ >=0 && i_ <m && j_ >=0 && j_ <n && !visited[i_][j_]){
                    water+=max(0,(height- heightMap[i_][j_]));
                    boundry_cell.push({ max(heightMap[i_][j_] , height),{i_,j_}});
                    visited[i_][j_]=true;
                }
            }
        }
        return water;
    }
};