class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        for(int i=0;i<intervals.size();i++){
            int st=intervals[i][0];
            int end=intervals[i][1];
            if(!ans.empty()){
                vector<int>back=ans.back();
                if(back[1]>=st){
                    ans.pop_back();
                    st=back[0];
                    end=max(end,back[1]);
                }
            }
            ans.push_back({st,end});
        }
        return ans;
    }
};