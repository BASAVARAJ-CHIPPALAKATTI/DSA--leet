class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int n=nums.size();
        int j=0;
        int count=0;
        while(j<n){
            while(j<n && abs(nums[i]-nums[j])<=k){
                j++;
            }
            i=j;
            count++;
        }
        return count;
    }
};