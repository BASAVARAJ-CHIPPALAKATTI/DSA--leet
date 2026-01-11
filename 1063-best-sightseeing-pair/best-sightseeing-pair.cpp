class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res=INT_MIN;
        int max_till_now=values[0]+0;
        for(int j=1;j<values.size();j++){
            int curr_eval = values[j]-j;

            res=max(res,max_till_now +curr_eval);

            max_till_now = max(max_till_now , values[j] +j);
        }
        return res;
    }
};