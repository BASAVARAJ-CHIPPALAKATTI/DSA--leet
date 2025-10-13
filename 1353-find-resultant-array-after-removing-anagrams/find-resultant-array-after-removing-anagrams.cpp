class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        // unordered_set<string>st;
        string prev=" ";
        for(string s : words){
            string curr=s;
            sort(curr.begin(),curr.end());
            if( prev!=curr){
                // st.insert(curr);
                ans.push_back(s);
            }
            prev=curr;

        }
        return ans;
    }
};