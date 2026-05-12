class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](vector<int>&a , vector<int>&b){
            return(a[1] - a[0]) > (b[1] - b[0]);
        });
        int ans=0;
        int currval=0;
        for(int i=0;i<tasks.size();i++){
            if(currval >= tasks[i][1]){
                currval-=tasks[i][0];
            }
            else{
                int val=tasks[i][1]-currval;
                ans+=val;
                currval+=val;
                currval-=tasks[i][0];
            }
        }
        return ans;
    }
};