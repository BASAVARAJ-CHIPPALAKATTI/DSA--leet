class Solution {
public:
    string getHappyString(int n, int k) {
        string curr="";
        vector<string>result;
        backtrack(n,curr,result);
        if(result.size()<k){
            return "";
        }
        return result[k-1];
    }
    void backtrack(int n,string curr,vector<string>&result){
        if(curr.size()==n){
            result.push_back(curr);
            return ;
        }
        for(char s='a';s<='c';s++){
            if(!curr.empty() && curr.back()==s){
                continue;
            }
            curr.push_back(s);
            backtrack(n,curr,result);
            curr.pop_back();
        }
    }
};