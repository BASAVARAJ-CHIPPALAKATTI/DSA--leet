class Solution {
public:
    //put all unique k substring map
    // if map size ()==pow(2,k) all are present
    bool hasAllCodes(string s, int k) {
        int possible_substring = 1<<k; //pow(2,k)
        unordered_set<string>st;
        for(int i=k;i<=s.size();i++){
            string sub=s.substr(i-k,k);
            if(!st.count(sub)){
                st.insert(sub);
                possible_substring--;
            }
            if(possible_substring==0){
                return true;
            }
        }
        return false;
    }
};