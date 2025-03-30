class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        //store last occurance of char
        vector<int>mp(26,-1);
        for(int i=0;i<s.size();i++){
            int idx=s[i]-'a';
            mp[idx]=i;
        }
        int i=0;
        int start=0;
        int end=0;
        while(i<s.size()){
            end=max(end,mp[s[i]-'a']); // last occurance
            if(i==end){
                ans.push_back(end-start+1);
                start=end+1;
            }
            i++;
        }
        return ans;
    }
};