class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int num : nums){
            st.insert(num);
        }
        int curr=0;
        int res=0;
        for(int num : st){
            if(st.count(num-1)){
                continue;
            }
            curr=0;
            while(st.count(num)){
                curr++;
                num++;
                res=max(res,curr);
            }
        }
        return res;
    }
};