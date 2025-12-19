//monotonic st
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>last(26,-1);
        for(int i=0;i<s.size();i++ ){
            last[s[i]-'a']=i;
        }
        string ans="";
        vector<bool>pushed(26,false);
        for(int i=0;i<s.size();i++){
            if(pushed[s[i]-'a']){
                continue;
            }
            while(ans.size()>0 && ans.back()-'a' > s[i]-'a' && last[ans.back()-'a'] > i){
                pushed[ans.back()-'a']=false;
                ans.pop_back();
            }

            ans.push_back(s[i]);
            pushed[s[i]-'a'] =true;
        }
        return ans;
    }
};