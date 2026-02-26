class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        while(s.size()>1){
            int n=s.size()-1;
            if(s[n]=='1'){ //odd
                ans++;
                addone(s);
            }
            else{  //even
                s.pop_back();
                ans++;
            }
        }
        return ans;
    }
    void addone(string &s){
        int i=s.size()-1;
        while(i >=0 && s[i]!='0'){
            s[i]='0';
            i--;
        }
        if(i<0){
            s='1'+s;
        }
        else{
            s[i]='1';
        }
    }
};