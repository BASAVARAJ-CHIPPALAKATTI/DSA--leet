class Solution {
public:
    string removeOccurrences(string s, string part) {
        int tarlen=part.size();
        char lstchar=part.back();
        string st;
        for(char & ch : s){
            st.push_back(ch);
            if(ch==lstchar && st.size()>=tarlen ){
                if(st.substr(st.size()-tarlen)==part){
                    st.erase(st.size()-tarlen);
                }
            }
        }
        return st;
    }
};