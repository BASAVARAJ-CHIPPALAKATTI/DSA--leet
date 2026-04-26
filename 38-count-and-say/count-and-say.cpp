class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        while(--n){
            string temp="";
            int count=1;
            int i;
            for( i=1;i<ans.size();i++){
                if(ans[i-1]==ans[i]){
                    count++;
                }
                else{
                    temp+=to_string(count)+(ans[i-1]);
                    count=1;
                }
            }
            temp+=to_string(count)+(ans[i-1]);
            ans=temp;
            
        }
        return ans;
    }
};