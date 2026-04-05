class Solution {
public:
    bool judgeCircle(string moves) {
        int left_right=0;
        int down_up=0;
        for( char move : moves){
            if(move=='L'){
                left_right++;
            }
            else if(move=='R'){
                left_right--;
            }
            else if(move=='U'){
                down_up++;
            }
            else{
                down_up--;
            }
        }
        if(left_right ==0 && down_up==0){
            return true;
        }
        return false;
    }

};