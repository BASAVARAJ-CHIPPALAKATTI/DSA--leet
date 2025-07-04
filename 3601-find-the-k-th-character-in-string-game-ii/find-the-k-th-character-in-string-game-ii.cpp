class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k==1){
            return 'a';
        }
        int n=operations.size();
        long long newk=0;
        int operval;
        long long len=1;
        for(int i=0;i<n;i++){
            len=len*2;
            if(len>=k){
                newk=k-len/2;
                operval=operations[i];
                break;
            }
        }
        char res=kthCharacter(newk, operations);
        if(operval==0){
            return res;
        }
        if(res=='z'){
            return 'a';
        }
        return res+1;
    }
};