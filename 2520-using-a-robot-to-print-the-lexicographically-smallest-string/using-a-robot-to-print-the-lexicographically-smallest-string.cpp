//initially pre compute from right to left which were small char are there 
// it helps to pop the t easily
class Solution {
public:
    string robotWithString(string s) {
        int n=s.size();
        vector<char>smallcharR2L(n);
        smallcharR2L[n-1]=s[n-1];
        for(int i=n-2;i>=0;i--){
            smallcharR2L[i]=min(smallcharR2L[i+1],s[i]);
        }
        string t="";
        string paper="";
        int i=0;
        while(i<n){
            t.push_back(s[i]);
            char minchar=(i+1 < n) ? smallcharR2L[i+1] : s[i];
            while(!t.empty() && t.back()<= minchar){
                paper+=t.back();
                t.pop_back();
            }
            i++;
        }
        while(!t.empty()){
            paper+=t.back();
            t.pop_back();
        }
        return paper;

    }
};