class Solution {
public:
    int findMin(vector<int>& nums) {
        // int ans=nums[0];
        int l=0;
        int h=nums.size()-1;
        while(l<h){
            int mid=l+(h-l)/2;
            if(nums[h] < nums[mid]){
                l=mid+1;
            }
            else{
                // ans=nums[mid];
                h=mid;
            }
        }
        return nums[h];
    }
};