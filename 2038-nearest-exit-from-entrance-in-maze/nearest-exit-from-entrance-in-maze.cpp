class Solution {
public:
    vector<vector<int>>direction={{0,1},{1,0},{-1,0},{0,-1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    
        queue<vector<int>>q;
        q.push(entrance);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                vector<int>curr=q.front();
                q.pop();
                if((curr!=entrance) &&(curr[0] ==0 || curr[0]==maze.size()-1 || curr[1]==0 || curr[1]==maze[0].size()-1)){
                    return level;
                }
                for(auto dir : direction){
                    int i=dir[0]+curr[0];
                    int j=dir[1]+curr[1];

                    if(i>=0 && i<maze.size() && j>=0 && j<maze[0].size() && maze[i][j]!='+' ){
                        q.push({i,j});
                        maze[i][j]='+';
                    }
                }
            }
            level++;
        }
        return -1;
    }
};