class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>ans;
        ans.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            string prev=ans.back();
            string curr=folder[i];
            prev+='/';
            if(curr.find(prev)){
                ans.push_back(curr);
            }
        }
        return ans;
    }
};