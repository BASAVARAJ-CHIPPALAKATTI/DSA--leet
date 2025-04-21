//go for hint 
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        // int min=INT_MAX;
        // int max=INT_MIN;
        long long min_=1;
        long long max_=1;
        long long curr=1;
        for(int i=0;i<differences.size();i++){
            min_=min(min_,differences[i]+curr);
            max_=max(max_,differences[i]+curr);
            curr=curr+differences[i];
        }
        int need_diff=upper-lower;
        int actual_diff=max_-min_;
        if(need_diff < actual_diff){
            return 0;
        }
        return (need_diff-actual_diff)+1;
    }
};