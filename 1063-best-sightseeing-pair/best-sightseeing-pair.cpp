/*
approach
values[i] + values[j] + i - j
make it this as
values[i]+i and values[j]-j 



*/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int res=INT_MIN;
        int max_till_now=values[0]+0;
        for(int j=1;j<n;j++){
            int x =values[j]-j;
            res=max(res,x+max_till_now);

            max_till_now=max(max_till_now,values[j]+j);
        }
        return res;
    }
};