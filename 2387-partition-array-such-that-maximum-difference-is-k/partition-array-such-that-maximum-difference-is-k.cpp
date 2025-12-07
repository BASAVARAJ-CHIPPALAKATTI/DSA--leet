class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int partition=0;
        int i=0;
        int j=0;
        int n=nums.size();
        while(j<n){
            while( j<n &&  (nums[j] - nums[i]) <= k){
                j++;
            }
            partition++;
            i=j;
        }
        return partition;

    }
};