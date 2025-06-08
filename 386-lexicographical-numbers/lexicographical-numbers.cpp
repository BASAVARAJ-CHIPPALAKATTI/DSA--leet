class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int start=1;start<=9;start++){
            appendit(start,n,ans);
        }
        return ans;
    }
    void appendit(int currnum,int n ,vector<int>&ans){
        if(currnum>n){
            return ;
        }
        ans.push_back(currnum);
        for(int i=0;i<=9;i++){
            int newnum=(currnum *10)+i;
            appendit(newnum,n,ans);
        }
    }
};