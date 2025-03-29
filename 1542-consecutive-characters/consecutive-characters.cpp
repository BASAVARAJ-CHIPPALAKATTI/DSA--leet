class Solution {
public:
    int maxPower(string s) {
        int ans=1;
        int curr=1;
        for(int i=1;i<s.size();i++){
            if(s[i-1]==s[i]){
                curr++;
                ans=max(ans,curr);
            }
            else{
                curr=1;
            }
        }
        return ans;
    }
};