/* approach
  make the freq arry keep track of it if there is freq of 2 than do count of it */
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>freq(n+1,0);
        vector<int>result(n);
        int count=0;
        for(int i=0;i<n;i++){
            if(++freq[A[i]]==2) ++count;
            if(++freq[B[i]]==2) ++count;
            result[i]=count;    
        }
        return result;
    }
};