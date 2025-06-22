class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        string temp;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(temp.size()==k){
                ans.push_back(temp);
                temp="";
            }
            temp.push_back(s[i]);
        }
        if(!temp.empty()){
            while(temp.size()<k){
                temp.push_back(fill);
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};