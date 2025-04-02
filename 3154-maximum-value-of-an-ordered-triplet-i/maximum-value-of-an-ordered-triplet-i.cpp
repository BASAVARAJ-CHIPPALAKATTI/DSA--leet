class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        vector<int>leftHigh(n);
        vector<int>rightHigh(n);

        leftHigh[0]=nums[0];
        rightHigh[n-1]=nums[n-1];
       
        for(int i=1;i<n;i++){
            leftHigh[i]=max(leftHigh[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            rightHigh[i]=max(rightHigh[i+1],nums[i]);
        }
        for(int i=1;i<=n-2;i++){   // left with first and left
            ans=max(ans,(long long)((long long)(leftHigh[i-1] - nums[i])*rightHigh[i+1]) );
        }
        return ans;
    }
};