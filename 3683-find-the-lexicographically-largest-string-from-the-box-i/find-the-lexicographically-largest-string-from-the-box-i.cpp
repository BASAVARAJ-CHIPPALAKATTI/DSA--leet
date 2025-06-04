class Solution {
public:
    string answerString(string word, int numFriends) {
        int n=word.size();
        if(numFriends==1){
            return word;
        }
        string ans="";
        int longest_possible=n-(numFriends-1);
        for(int i=0;i<n;i++){
            int minlen=min(longest_possible,n-i);
            ans=max(ans,word.substr(i,minlen));
        }
        return ans;
    }
};