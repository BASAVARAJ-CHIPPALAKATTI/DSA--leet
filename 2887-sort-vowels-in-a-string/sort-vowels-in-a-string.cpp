class Solution {
public:
    string sortVowels(string s) {
        vector<char>st;
        for(int i=0;i<s.size();i++){
            char c=tolower(s[i]);
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                st.push_back(s[i]);
            }
        }
        sort(st.begin(),st.end());
        int idx=0;
        for(int i=0;i<s.size();i++){
            char c=tolower(s[i]);
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                s[i]=st[idx++];
            }
        }
        return s;

    }
};