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


//  string res;
//         int n=s.length();
//         for(int i=0;i<n;i++)
//         {
//             if(s[i]=='*')
//             {
//                 res.pop_back();
//             }
//             else
//             {
//                 res.push_back(s[i]);
//             }
//         }
//         return res;


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