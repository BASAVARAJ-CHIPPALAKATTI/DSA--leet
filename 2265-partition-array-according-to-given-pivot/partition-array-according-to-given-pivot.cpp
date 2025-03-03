class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int i=0;
        int j=nums.size()-1;

        int i_=0;
        int j_=nums.size()-1;
        vector<int>result(nums.size());
        while(i<nums.size() && j>=0){
            if(nums[i]<pivot){
                result[i_]=nums[i];
                i_++;
            }
            if(nums[j]>pivot){
                result[j_]=nums[j];
                j_--;
            }
            i++;
            j--;
        }
        while(i_<=j_){
            result[i_]=pivot;
            i_++;
        }
        return result;
    }
};