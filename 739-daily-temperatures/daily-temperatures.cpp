// use stack and store the idx
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        vector<int>ans(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){
            while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                int idx=st.top();
                ans[idx]=i-idx;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};