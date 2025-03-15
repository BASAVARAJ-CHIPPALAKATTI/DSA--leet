// take min and max from nums and we will find ans in between that
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l=*min_element(nums.begin(),nums.end());
        int h=*max_element(nums.begin(),nums.end());
        int result=0;
       
        while(l<=h){
            int mid=l+(h-l)/2;
            if(isPossible(nums,mid,k)){
                result=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
        
    }
    bool isPossible(vector<int>&nums,int mid,int k){
        int count=0; //we need count of k
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                count++;
                i++; //skip neighbour element
            }
        }
        return (count>=k);
    }
};