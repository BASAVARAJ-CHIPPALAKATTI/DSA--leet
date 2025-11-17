class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int kplace=k;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                kplace++;
            }
            else{
                if(kplace < k){
                    return false;
                }
                kplace=0;
            }
        }
        return true;
    }
};