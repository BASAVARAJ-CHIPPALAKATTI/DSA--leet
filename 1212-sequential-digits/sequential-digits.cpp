class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i=1;i<10;i++){
            string curr=to_string(i);
            solve(curr,ans,low,high);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    void solve(string curr,vector<int>&ans,int low,int high){
        long long val=stoi(curr);
        if(val > high){
            return ;
        }
        if(val >= low && val <= high){
            ans.push_back(val);
        }
        int last=val % 10;
        if(last <=8){
            string c=to_string(last+1);
            curr=curr+c;
            solve(curr,ans,low,high);
        }
    }

};