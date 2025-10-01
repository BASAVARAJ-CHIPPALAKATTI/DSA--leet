class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if(numBottles < numExchange){
            return numBottles;
        }
        int ans=numBottles;
        int remains=0;
        while(true){
            remains+=numBottles / numExchange;
            ans+=remains;
            remains+=numBottles%numExchange;

            if(remains < numExchange){
                break;
            }
            numBottles=remains;
            remains=0;
        }
        return ans;
    }
};