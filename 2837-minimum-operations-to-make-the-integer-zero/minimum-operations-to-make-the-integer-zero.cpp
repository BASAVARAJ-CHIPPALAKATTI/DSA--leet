class Solution {
public:

// https://www.youtube.com/watch?v=YLKbecs9LIU
    int makeTheIntegerZero(int num1, int num2) {
        int k=0;
        while(true){
            long long val=(long long)num1- (long long) k* num2;
            if(val <0){
                return -1;
            }
            if(__builtin_popcountll(val) <=k  && k <= val){
                return k;
            }
            k++;
        }
        return -1;
    }
};