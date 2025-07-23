class Solution {
public:
    int ans=0;
    stack<char>st;
    int maximumGain(string s, int x, int y) {

        int maxval=0;
        int minval=0;
        string str1;
        string str2;

        if(x>y){
            maxval=x;
            minval=y;

            str1="ab";
            str2="ba";
        }
        else{
            maxval=y;
            minval=x;

            str1="ba";
            str2="ab";
        }
        solve(s,maxval,str1);
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        solve(s,minval,str2);
        return ans;
    }
    void solve(string s,int val,string str){
        int i=0;
        while(i<s.size()){
            if(!st.empty()&& st.top()==str[0] && s[i]==str[1]){
                ans+=val;
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
    }
};