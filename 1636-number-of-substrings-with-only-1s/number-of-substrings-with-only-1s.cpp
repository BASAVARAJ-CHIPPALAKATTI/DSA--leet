class Solution {
public: 
    int M =1e9+7;
    int numSub(string s) {
        long long  ans=0;
        long long count_one=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                ans= (ans + ((count_one * (count_one+1))/2) %M ) % M ;
                count_one=0;
            }
            else{
                count_one++;
           }
        }
        ans = (ans + ((count_one * (count_one+1))/2) %M ) % M ;
        return ans;
    }
};