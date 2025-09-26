//two pointers
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        sort(nums.begin(),nums.end());
        for( int k=n-1;k>=2;k--){
            int i=0;
            int j=k-1;

            while(i<j){
                if((nums[i]+nums[j]) > nums[k]){
                    count+=j-i;// (i, j-1)pair ( j)pari (k) pari
                    j--;
                }
                else{
                    i++;
                }
            }
        }
        return count;
    }
};