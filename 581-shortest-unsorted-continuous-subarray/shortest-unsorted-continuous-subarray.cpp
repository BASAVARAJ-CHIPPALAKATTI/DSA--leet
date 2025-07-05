class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>sortednums=nums;
        sort(sortednums.begin(),sortednums.end());
        int i=0;
        int j=nums.size()-1;
        while(i<=j){
            if(nums[i]!=sortednums[i]  && nums[j]!=sortednums[j]){
                break;
            }
            if(nums[i]==sortednums[i]) i++;
            if(nums[j]==sortednums[j]) j--;

        }
        return (i>j) ? 0 : j-i+1;
    }
};