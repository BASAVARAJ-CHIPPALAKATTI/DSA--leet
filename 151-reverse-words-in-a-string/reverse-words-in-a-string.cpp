class Solution {
public:
    string reverseWords(string s) {
        //-> using string strea(it stores the words separted by space )    
        // stringstream ss(s);
        // string ans;
        // string token;
        // while(ss >> token){
        //     ans=token+" "+ans;
        // }
        // return ans.substr(0,ans.size()-1);

        reverse(s.begin(),s.end());
        int left=0;
        int right=0;
        int i=0;
        while(i < s.size()){
            while(i<s.size() && s[i]!=' '){
                s[right++]=s[i++];
            }
            if(left<right){
                reverse(s.begin()+left,s.begin()+right);
                s[right++]=' ';
                left=right;
            }
            i++;
        }
        return s.substr(0,right-1);
    }
};