class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<int>st(nums.begin(),nums.end());
        if(nums[0]+nums[1] <=nums[2]){
            return "none";
        }
        if(st.size()==1){
            return "equilateral";
        }
        if(st.size()==2){
            return "isosceles";
        }    
        return "scalene";
        
    }
};