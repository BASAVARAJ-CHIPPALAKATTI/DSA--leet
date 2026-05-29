class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1){
            sort(s.begin(),s.end());
            return s;
        }
        string ans=s;
        for(int i=0;i<s.size();i++){
            char c=s[0];
            s.erase(0, 1);
            s.push_back(c);
            ans=min(ans,s);
        }
        return ans;
    }
};