class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int ans=1;
        sort(nums.begin(),nums.end());
        int prev=nums[0]-k;
        for(int i=1;i<nums.size();i++){
            int curr=nums[i]-k;
            if(prev < curr){
                prev=curr;
                ans++;
            }
            else{
                if( prev +1 <= nums[i]+k){
                    prev++;
                    ans++;
                }
            }
        }
        return ans;
    }
};