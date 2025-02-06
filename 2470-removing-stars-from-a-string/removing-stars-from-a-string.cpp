//own
class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        int i=0;
        while(i<s.size()){
            if(!st.empty() && s[i]=='*'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};