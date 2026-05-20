class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int count=0;
        vector<int>freq(51,0);
        vector<int>ans(A.size());
        for(int i=0;i<A.size();i++){
            freq[A[i]]++;

            if(freq[A[i]] > 1){
                count++;
            }
            
            freq[B[i]]++;
            
            if(freq[B[i]] > 1){
                count++;
            }
            ans[i]=count;
        }
        return ans;
    }
};