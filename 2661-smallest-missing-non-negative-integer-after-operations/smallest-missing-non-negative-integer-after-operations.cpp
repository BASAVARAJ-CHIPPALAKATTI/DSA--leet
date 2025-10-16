class Solution {
public:
//understand the problem than see hint
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>mp;

        for(int num : nums){
            int n = ((num%value)+value)%value;  //helps for negative val 
            mp[n]++;
        }
        int MEX=0;
        while(mp[MEX % value] > 0){
            mp[MEX % value]--;
            MEX++;
        }
        return MEX;
    }
};