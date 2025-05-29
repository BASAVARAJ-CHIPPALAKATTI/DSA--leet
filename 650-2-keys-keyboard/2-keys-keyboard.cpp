class Solution {
public:
    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        return 1+solve(1,1,n);  //1+ we copied that
    }
    int solve(int currA,int clipA,int n){
        if(currA==n){
            return 0;
        }
        if(currA> n){
            return 10000;  //return maxone for we need to consider
        }
        int copy_and_paste=1+1+solve(currA+currA,currA,n) ;// we copy the all and paste
        int paste=1+solve(currA+clipA,clipA,n);  //paste only

        return min(copy_and_paste,paste);
    }
};