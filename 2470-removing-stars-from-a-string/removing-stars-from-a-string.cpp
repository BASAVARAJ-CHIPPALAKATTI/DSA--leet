//own
class Solution {
public:
    string removeStars(string s) {
        // stack<char>st;
        // int i=0;
        // while(i<s.size()){
        //     if(!st.empty() && s[i]=='*'){
        //         st.pop();
        //     }
        //     else{
        //         st.push(s[i]);
        //     }
        //     i++;
        // }
        // string ans="";
        // while(!st.empty()){
        //     ans+=st.top();
        //     st.pop();
        // }
        // reverse(ans.begin(),ans.end());
        // return ans;

        int pos=0;
        for( char &c : s){
            if(c=='*'){
                pos--;
            }
            else{
                s[pos++]=c;
            }
        }
        s.resize(pos);
        return s;
    }
};