class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int i=0,j=0;
        int ans=1;
        while(j < nums.size()){
            if( i<j && nums[j] > (long long)nums[i]*k){
                i++;
            }
            ans=max(ans, j-i+1);
            j++;
            
        }
        return nums.size()-ans;
    }
};