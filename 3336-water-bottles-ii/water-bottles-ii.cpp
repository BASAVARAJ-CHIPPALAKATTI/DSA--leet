class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        if(numBottles < numExchange){
            return numBottles;
        }
        int ans=numBottles;
        int remains=numBottles;

        while(remains >= numExchange){
            remains-=numExchange;
            numExchange++;
            remains++;
            ans++;
        }
        return ans;
    }
};