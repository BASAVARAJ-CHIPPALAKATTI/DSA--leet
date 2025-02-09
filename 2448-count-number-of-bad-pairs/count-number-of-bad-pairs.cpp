class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long goodpairs=0;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            goodpairs+=mp[nums[i]-i];
            mp[nums[i]-i]++;
        }
        long long n=nums.size();
        return (n*(n-1)/2) -goodpairs;
    }
};