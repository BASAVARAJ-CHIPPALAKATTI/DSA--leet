//
class Solution {
public:
    int  M=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<int>freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        int res=0;
        for(int j=0;j<t;j++){
            vector<int>temp(26,0);
            for(int i=0;i<26;i++){
                if(i==25){
                    temp[0]= (temp[0] + freq[25])%M;
                    temp[1]= (temp[1] +freq[25])%M;
                }
                else{
                    temp[i+1]=freq[i];
                }
            }
            freq=temp;
        }
        for(int i=0;i<26;i++){
            res=(res+freq[i])%M;
        }
        return res;
    }
};