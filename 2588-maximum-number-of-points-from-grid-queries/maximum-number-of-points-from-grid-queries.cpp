// Sort Queries: Sort the queries along with their original indices to process them in increasing order.

// Priority Queue BFS: Use a min-heap (priority queue) to explore the grid in increasing cell value order, starting from (0,0).

// Answer Queries: Process each query by expanding reachable cells until the top of the heap meets or exceeds the query value, storing the count of visited cells.
class Solution {
public:
    vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m=grid.size();
        int n=grid[0].size();
        int q=queries.size();

        vector<int>res(q,0);

        vector<pair<int,int>>qsorted;
        for(int i=0;i<q;i++){
            qsorted.push_back({queries[i],i});
        }

        sort(qsorted.begin(),qsorted.end());

        vector<vector<bool>>visited(m,vector<bool>(n,false)); //to avoid repeataion
        priority_queue<vector<int>,vector<vector<int>>, greater<>>minh;
        minh.push({grid[0][0],0,0});
        visited[0][0]=true;
        int points=0;

        for(int i=0;i<q;i++){
            int qval=qsorted[i].first;
            int qidx=qsorted[i].second;
            while(!minh.empty() && minh.top()[0] < qval){
                int x=minh.top()[1];
                int y=minh.top()[2];

                minh.pop();
                points++;
                for(auto direction:directions){
                    int i_= x+direction[0];
                    int j_= y+direction[1];

                    if(i_ >=0 && i_<m && j_>=0 && j_<n && !visited[i_][j_]){
                        minh.push({grid[i_][j_],i_,j_});
                        visited[i_][j_]=true;
                    }
                }
            }
            res[qidx]=points;
        }
        return res;
    }
};