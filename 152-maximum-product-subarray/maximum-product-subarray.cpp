class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=INT_MIN;
        int n=nums.size();
        int left=1;
        int right=1;
        for(int i=0;i<n;i++){
            left*=nums[i];
            res=max(res,left);
            if(left==0){
                left=1;
            }

            right*=nums[n-i-1];
            res=max(res,right);
            if(right==0){
                right=1;
            }
        }
        return res;
    }
};