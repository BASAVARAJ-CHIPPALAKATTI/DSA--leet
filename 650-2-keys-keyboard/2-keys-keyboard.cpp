class Solution {
public:
    int solve(int currA , int clipA,int n){
        if(currA==n){
            return 0;
        }
        if(currA > n){
            return 1000;
        }
        int copy_paste=2+solve(currA+currA,currA,n);
        int paste=1+solve(currA+clipA,clipA,n);
        return min(copy_paste,paste);
    }
    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        return 1+solve(1,1,n);
    }
};