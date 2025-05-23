// approach sorting and two pointers
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int i=0;
        int j=nums.size()-1;
        sort(nums.begin(),nums.end());
        int countPairs=0;
        while(i<j){
            if(nums[i]+nums[j]==k){
                countPairs++;
                i++;
                j--;
            }
            else if(nums[i]+nums[j]< k){ //sum is less than k we need to move i val to make sum large
                i++;
            }
            else{              
                j--;
            }
        }
        return countPairs;
    }
};