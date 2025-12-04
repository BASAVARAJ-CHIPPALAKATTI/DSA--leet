class Solution {
public:
    int countCollisions(string directions) {
        // just remove L from starting and R from last beacuse they no collide only
        int n=directions.size();
        int i=0;
        int j=directions.size()-1;
        while(   directions[i]=='L' && i < n){
            i++;
        }
        while(j>=0 && directions[j]=='R'){
            j--;
        }

        int collision=0;
        while(i <= j){
            if(directions[i]=='L' || directions[i]== 'R'){
                collision++;
            }
            i++;
        }
        return collision;
    }
};