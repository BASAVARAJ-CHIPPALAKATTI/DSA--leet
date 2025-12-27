class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int pref=1;
        int suf=1;
        int res=INT_MIN;
        for(int i=0;i<n;i++){
            pref=pref*nums[i];
            res=max(res,pref);
            if(pref==0){
                pref=1;
            }

            suf=suf*nums[n-i-1];
            res=max(res,suf);
            if(suf==0){
                suf=1;
            }
        }
        return res;
    }
};