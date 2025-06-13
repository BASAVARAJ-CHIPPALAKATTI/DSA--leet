//easy one
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=0;
        int high=nums[n-1]-nums[0];
        int ans=high; //anything initially
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isvalid(nums,mid,p)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    bool isvalid(vector<int>&nums,int mid,int p){
        int pairs=0;
        int i=0;
        int n=nums.size();
        while(i<n-1){
            if((nums[i+1]-nums[i]) <= mid){
                pairs++;
                i+=2;
            }
            else{
                i++;
            }
        }
        return (pairs>=p);
    }
};