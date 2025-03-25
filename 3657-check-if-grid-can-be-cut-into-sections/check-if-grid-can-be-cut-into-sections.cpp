class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>xintervals;
        vector<vector<int>>yintervals;
        for(int i=0;i<rectangles.size();i++){
            xintervals.push_back({rectangles[i][0],rectangles[i][2]});
            yintervals.push_back({rectangles[i][1],rectangles[i][3]});
        }
        return(merge(xintervals)>=3 || merge(yintervals)>=3); // we need atleaset 3 reactangles
    }

    int merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        res.push_back(intervals[0]);
        for(int i=0;i<intervals.size();i++){
            if(res.back()[1]>intervals[i][0]){ //ovarlap
                res.back()[1]=max(res.back()[1] ,intervals[i][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res.size();
    }
};