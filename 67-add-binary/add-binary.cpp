class Solution {
public:
    string addBinary(string a, string b) {
        char carry='0';
        string ans;
        int i=a.size()-1;
        int j=b.size()-1;
        while(i >=0 || j>=0 ){
           int sum=0;
           sum += carry-'0';
           if(i>=0){
            sum+=a[i]-'0';
            i--;
           }
           if(j>=0){
            sum+=b[j]-'0';
            j--;
           }

           if(sum >= 2){
            carry='1';
           }
           else{
            carry='0';
           }
           ans.push_back( (sum%2==0) ? '0': '1');
        }
        if(carry=='1'){
            ans.push_back('1');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};