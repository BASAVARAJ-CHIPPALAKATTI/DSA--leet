class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_set<int>st;
        for(int num :nums){
            st.insert(num);
        }
        for(int num : st){
            int currans=0;
            if(!st.count(num-1)){
               int j=num;
               while(st.count(j)){
                currans++;
                j++;
               }
            }
            ans=max(ans,currans);
        }
        return ans;
    }
};