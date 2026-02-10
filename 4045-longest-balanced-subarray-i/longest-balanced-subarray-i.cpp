class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans =0;
        for(int i=0;i<nums.size();i++){
            set<int>evenst;
            set<int>oddst;
            int j;
            for(int j=i;j<nums.size();j++){
                if(nums[j] % 2 ==0){
                    evenst.insert(nums[j]);
                }
                else{
                    oddst.insert(nums[j]);
                }
                if(evenst.size() == oddst.size()){
                   ans = max(ans , j-i+1);
                }
            }
           
        }
        return ans;
    }
};