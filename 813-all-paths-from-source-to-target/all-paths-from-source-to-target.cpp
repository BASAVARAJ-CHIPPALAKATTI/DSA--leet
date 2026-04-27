class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>currans;
        currans.push_back(0);
        solve(graph,0,graph.size()-1,currans);
        return res;
    }
    void solve(vector<vector<int>>&graph,int curr,int desti,vector<int>currans){
        if(curr==desti){
            res.push_back(currans);
            return ;
        }
        for (int val : graph[curr]){
            currans.push_back(val);
            solve(graph,val,desti,currans);
            currans.pop_back();
        }
    }
};