class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int res=0;
        while(target!=1){
            if(target %2 ==0){
                if(maxDoubles==0){
                    return res+=target-1;
                }
                else{
                    target /=2;
                    maxDoubles--;
                    res++;
                }
            }
            else{
                target-=1;
                res++;
            }
        }
        return res;
    }
};