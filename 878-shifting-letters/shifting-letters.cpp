//easy one
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=shifts.size();
        vector<int>shiftsum(n,0);
        shiftsum[n-1]=(shifts[n-1])%26;
        for(int i=n-2;i>=0;i--){
            shiftsum[i]=(shifts[i]+shiftsum[i+1])%26;
        }
        for(int i=0;i<n;i++){
            s[i]='a'+((s[i]-'a')+shiftsum[i])%26;
        }
        return s;
    }
};