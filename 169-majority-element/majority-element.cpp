class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elt=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==elt){
            count++;
            }
            else
            count--;
            if(count==0){
                elt=nums[i+1];
            }
        }
        return elt;
    }
};