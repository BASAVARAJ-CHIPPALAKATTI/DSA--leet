//similar to longest common sub-seq
class Solution {
public:
    int t[1001][1001];
    int minimumDeleteSum(string s1, string s2) {
        memset(t,-1,sizeof(t));
        return solve(0,0,s1,s2);
    }
    int solve(int i ,int j,string &s1, string &s2){
        if(i >=s1.size() && j >= s2.size()){
            return 0;
        }
         if(t[i][j]!=-1){
            return t[i][j];
        }
        if(i >= s1.size()){
            return  t[i][j]=s2[j] + solve(i,j+1,s1,s2);
        }
        if(j >= s2.size()){
            return s1[i] + solve(i+1,j,s1,s2);
        }
        if(s1[i] == s2[j]) {     //no deletion needed
            return t[i][j]= solve(i+1,j+1,s1,s2);
        }
       
        int take_i = s1[i] + solve(i+1,j,s1,s2);
        int take_j = s2[j] + solve(i,j+1,s1,s2);

        return t[i][j]= min(take_i ,take_j);
    }
};