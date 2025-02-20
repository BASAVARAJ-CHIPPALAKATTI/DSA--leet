//-own
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string>st;
        for(string &num: nums){
            st.insert(num);
        }
        int size=nums[0].size();
        string curr="";
        string ans=backtrack(st,size,curr);
        return ans;
    }
    string backtrack(set<string>st,int n,string curr){
        if(curr.size()==n){
            if(st.find(curr)==st.end()){
                return curr;
            }
            return "";
        }
        for(char i='0';i<='1';i++){
            curr.push_back(i);
            string res=backtrack(st,n,curr);
            if(!res.empty()) return res;          // we get curr from recurrsion
            curr.pop_back();
        }
        return "";
    }
};