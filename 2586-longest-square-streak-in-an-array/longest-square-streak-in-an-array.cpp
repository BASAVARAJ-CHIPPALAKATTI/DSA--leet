class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<float>st(nums.begin(),nums.end());
        int res=-1;
        for(int i=0;i<nums.size();i++){
            int currans=1;
            float sq=sqrt(nums[i]);
            while(st.count(sq)){
                currans++;
                sq=sqrt(sq);
                res=max(res,currans);
            }
        }
        return res;
    }
};