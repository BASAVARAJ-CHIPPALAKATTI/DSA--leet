class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        vector<int>bit(32,-1);
        
        for(int i=n-1;i>=0;i--){
            int endidx=i;
            for(int j=0;j<32;j++){
                if(!(nums[i] & 1<<j)){
                    endidx=max(endidx,bit[j]);
                }
                else{
                    bit[j]=i;
                }
            }
            ans[i]=endidx-i+1;
        }
        return ans;
    }
};