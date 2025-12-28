class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>LIS(n,1); 
        vector<int>RIS(n,1);
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i] > nums[j]){
                    LIS[i]=max(LIS[i],LIS[j]+1);
                }
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[i] > nums[j]){
                    RIS[i]=max(RIS[i],RIS[j]+1);
                }
            }
        }
        int minremovals=n;
        for(int i=0;i<n;i++){
            if(LIS[i] >1  && RIS[i]>1){
               minremovals=min(minremovals, n-LIS[i]-RIS[i]+1);
            }
        }
        return minremovals;
    }
};