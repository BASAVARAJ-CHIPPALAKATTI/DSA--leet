class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int count=1;
        int remind=1;
        while(count <=k ){
            if(remind % k ==0){
                return count;
            }
            remind = ((remind * 10 )+1) % k;
            count++;
        }
        return -1;
    }
};