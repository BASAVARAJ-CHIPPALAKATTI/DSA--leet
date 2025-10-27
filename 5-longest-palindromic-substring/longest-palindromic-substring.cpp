class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            int low=i;
            int high=i;
            while(low >=0 && high <n && s[low]==s[high]){
                if(ans.size() < high-low+1){
                    ans=s.substr(low,high-low+1);
                }
                low--;
                high++;
            }

            low=i;
            high=i+1;
            while(((low >=0) && (high <n)) && (s[low]==s[high])){
                if(ans.size() < high-low+1){
                    ans=s.substr(low,high-low+1);
                }
                low--;
                high++;
            }
        }
        return ans;
    }
};