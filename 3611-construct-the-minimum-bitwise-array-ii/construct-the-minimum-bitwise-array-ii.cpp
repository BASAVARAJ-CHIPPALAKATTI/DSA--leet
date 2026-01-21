//observeing
//https://www.youtube.com/watch?v=RnCZCzFivl8&t=1978s
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==2){
                ans.push_back(-1);
                continue;
            }
            bool found=false;
            for(int j=1;j<32;j++){
                if((nums[i] & (1<<j))){
                    continue;
                }
                found=true;
                int val = nums[i] ^ (1 << (j-1));
                ans.push_back(val);
                break;
            }
            if(!found){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};