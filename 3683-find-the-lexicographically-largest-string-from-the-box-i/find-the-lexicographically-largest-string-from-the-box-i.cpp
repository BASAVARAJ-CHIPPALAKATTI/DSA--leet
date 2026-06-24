class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1){
            return word;
        }
        string ans="";
        int n=word.size();
        int size=n-numFriends+1;
        for(int i=0;i<word.size();i++){
            string curr=word.substr(i,size);
            ans=max(ans,curr);
        }
        return ans;
    }
};