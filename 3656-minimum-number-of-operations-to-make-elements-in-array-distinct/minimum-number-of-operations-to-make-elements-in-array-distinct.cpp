//use less
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int>freq(101,0);
        int i;
        for( i=nums.size()-1;i>=0;i--){
            if(++freq[nums[i]] > 1){
                return (i/3)+1;
            }
        }
        return 0;
    }
};