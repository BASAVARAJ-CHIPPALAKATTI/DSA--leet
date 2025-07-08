class Solution {
public:
    int  n;
    vector<int>sttime; //for efficiency binary search
    vector<vector<int>>t;
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        n=events.size();
        t.resize(n+1,vector<int>(k+1,-1));
        for(vector<int> event : events){
           sttime.push_back(event[0]);
        }
        return solve(events,0,k);
       
    }
    int solve(vector<vector<int>>&events ,int idx, int k){
        if(idx >= n || k<=0){
            return 0;
        }
        if(t[idx][k]!=-1){
            return t[idx][k];
        }

        int st=events[idx][0];
        int end=events[idx][1];
        int val=events[idx][2];

        // for skip
        int skip=solve(events,idx+1,k);

        // for take
        
        // int j=idx+1;
        // for( ;j<n;j++){
        //     if(events[j][0] > end){
        //         break;
        //     }
        // }
        int j=upper_bound(sttime.begin(),sttime.end(),end)-sttime.begin();
        int take=val+solve(events,j,k-1);
        return t[idx][k]=max(skip,take);
    }
};