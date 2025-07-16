//easy 
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int counteven=0;
        int countodd=0;
        for(int num : nums){
            if(num%2==0){
                counteven++;
            }
            else{
                countodd++;
            }
        }
        //for alternation condtion
        int prev=nums[0]%2;
        int alter=1;
        for(int i=1;i<nums.size();i++){
            int curr=nums[i]%2;
            if(prev!=curr){
                alter++;
                prev=curr;
            }
        }
        return max({counteven,countodd,alter});
    }
};