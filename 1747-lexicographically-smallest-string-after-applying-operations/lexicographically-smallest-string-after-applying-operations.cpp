//easy
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string>st;
        string min_str=s;
        dfs( s,a,b,min_str,st);
        return min_str;
    }
    void dfs(string s,int a,int b,string &min_str,unordered_set<string>&st){
        if(st.count(s)){
            return ;
        }
        st.insert(s);
        if(s < min_str){
            min_str=s;
        }
        //add
        string diff=s;
        for(int i=1;i<s.size();i+=2){
            diff[i]= ((s[i]-'0' + a)%10) +'0';
        }
        dfs(diff,a,b,min_str,st);

        //or rotate
        rotate(s,b);
        dfs(s,a,b,min_str,st);

    }
    void rotate(string &s,int b){
        reverse(s.begin(),s.end());
        reverse(s.begin(),s.begin()+b);
        reverse(s.begin()+b,s.end());

    }
};