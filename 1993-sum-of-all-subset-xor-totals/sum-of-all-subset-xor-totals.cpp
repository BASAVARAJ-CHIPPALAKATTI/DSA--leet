/*
 observe the all nums bit and output
  ans=make or of all nums and append size-1 0's at right handside (left shift)
 
*/
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ans |=nums[i];
        }
        ans <<= (n-1);
        return ans;
    }
};