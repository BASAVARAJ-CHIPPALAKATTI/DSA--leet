//monotonic st
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>last(26,-1);
        for(int i=0;i<s.size();i++ ){
            last[s[i]-'a']=i;
        }
        vector<int>st;
        vector<bool>pushed(26,false);
        for(int i=0;i<s.size();i++){
            if(pushed[s[i]-'a']){
                continue;
            }
            while(!st.empty() && st.back() > s[i]-'a' && last[st.back()] > i){
                pushed[st.back()]=false;
                st.pop_back();
                
            }
            st.push_back(s[i]-'a');
            pushed[s[i]-'a'] =true;
        }

        string ans="";
        for(int i=0;i<st.size();i++){
            ans.push_back(st[i]+'a');
        }
        return ans;
    }
};