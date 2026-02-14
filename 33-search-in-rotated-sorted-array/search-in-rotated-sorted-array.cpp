class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size()-1;
        while(l < h){
            int mid= l+(h-l)/2;
            if(nums[mid] > nums[h]){
                l=mid+1;
            }
            else{
                h=mid;
            }
        }
        int ans=-1;
        ans=find_tar_elt(nums,target,h,nums.size()-1); // [4,5,6,7,     0,1,2] divide do binary ser
        if(ans !=-1){
            return ans;
        }
        ans=find_tar_elt(nums,target,0,h-1); 

        return ans;
    }
    int find_tar_elt(vector<int>&nums,int tar,int l,int h){
        while(l <= h){
            int mid=l+(h-l)/2;
            if(nums[mid]==tar){
                return mid;
            }
            else if(nums[mid] > tar){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
    }
    
};