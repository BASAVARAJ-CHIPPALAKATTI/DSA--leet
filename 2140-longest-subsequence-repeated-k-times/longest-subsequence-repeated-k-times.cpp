class Solution {
public:
    string res="";
    string longestSubsequenceRepeatedK(string s, int k) {
        int n=s.size();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        vector<bool>canuse(26,false);
        vector<int>requiredfreq(26,0);
        for(int i=0;i<26;i++){
            if(freq[i] >= k){
                canuse[i]=true;
                requiredfreq[i]=freq[i]/k;
            }
        }
        int maxlen=n/k; //for ans maxlen;
        string curr;
        backtracking(s, curr, canuse, requiredfreq, k, maxlen);
        return res;
    }
    void backtracking(string s,string &curr,vector<bool>&canuse,vector<int>&requiredfreq,int k,int maxlen){
        if(curr.size()> maxlen){
            return;
        }
        if(curr.size() >= res.size() && curr>res && issubseq(curr,s,k) ){
            res=curr;
        }
        for(int i=0;i<26;i++){
            if(canuse[i]==false || requiredfreq[i] ==0){
                continue;
            }
            char c=i+'a';
            curr.push_back(c);
            requiredfreq[i]--;
            backtracking(s, curr, canuse, requiredfreq, k, maxlen);

            curr.pop_back();
            requiredfreq[i]++;
        }
    }
    bool issubseq(string curr,string s,int k){
        int i=0;
        int j=0;
        int n=s.size();
        int L=curr.size();
        while(i<n && j<L*k){
            if(s[i]==curr[j%L]){
                j++;
            }
            i++;
        }
        return j==k*L;
    }
};