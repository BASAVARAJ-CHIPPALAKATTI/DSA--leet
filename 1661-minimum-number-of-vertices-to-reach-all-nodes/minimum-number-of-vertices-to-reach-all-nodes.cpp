class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool>incoming(n,false);
        for(int i=0;i<edges.size();i++){
            incoming[edges[i][1]]=true;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!incoming[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};