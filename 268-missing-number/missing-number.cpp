class Solution {
public:
    long long actual=0;
    long long now=0;
    int missingNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            actual+=i;
            now+=nums[i];
        }
        return (actual+nums.size())-now;
    }
};