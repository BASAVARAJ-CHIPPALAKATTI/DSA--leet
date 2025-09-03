class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        while(n-->1){
            string temp="";
            int count=1;
            int j;
            for(j=1;j<ans.size();j++){
                if(ans[j]==ans[j-1]){
                    count++;
                }
                else{
                    temp+=to_string(count)+ans[j-1];
                    count=1;
                }
            }
            temp+=to_string(count)+ans[j-1];
            ans=temp;
        }
        return ans;
    }
};