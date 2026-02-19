class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev=-1;
        int ans=0;
        int curr=1;
        for(int i=1;i<s.size();i++){
            if(s[i-1]==s[i]){
                curr++;
            }
            else{
                if(prev!=-1){
                    ans+=min(curr,prev);
                }
                prev=curr;
                curr=1;
            }
        }
        if(prev!=-1){
            ans+=min(curr,prev);
        }
        return ans;
    }
};