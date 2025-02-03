//own
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int result=1;
        int incr=1;
        int decr=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                incr=1;
                decr=1;
                continue;
            }
            else if(nums[i]<nums[i+1]){
                incr++;
                result=max(result,incr);
                decr=1;
            }
            else{
                decr++;
                result=max(result,decr);
                incr=1;
            }
        }
        return result;
    }
};