class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(nums.begin(),nums.end());
        sort(temp.begin(),temp.end());
        int count=0;
        int i=0;
        while(i<n){
            if(nums[i]!=temp[i]){
                break;
            }
            else{
                count++;
            }
            i++;
        }
        int j=n-1;
        while(j>=0 && j>i){
            if(nums[j]!=temp[j]){
                break;
            }
            else{
                count++;
            }
            j--;
        }
        
        
        return n-count;
    }
};