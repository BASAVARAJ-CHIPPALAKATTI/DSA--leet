class Solution {
public:
//worst case timp complexity O(n^2)
    int countPairs(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,vector<int>>pos;
        for(int i=0;i<nums.size();i++){

            for(int j : pos[nums[i]]){
                if(i*j % k==0){
                    count++;
                }
            }
            pos[nums[i]].push_back(i);
        }
        return count;
    }
};