class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            if(primecheck(__builtin_popcount(i))){
                ans++;
            }
        }
        return ans;
    }
    bool primecheck(int n){
        if(n==2 || n==3 || n==5 || n==7|| n==11|| n==13|| n==17 || n==19){
            return true;
        }
        return false;
    }
};