// traverse= reverse loop from 2nd last elt
// make it last one as var=lastreachable elt
// evey time do that elemet is lastreachable
// it it is reachable than change var to it's index and check that any elt recachable this lastreachable
// it will do again and again if we get the 0 it's true
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int dest=n-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]+i >= dest){
                dest=i;
            }
        }
        return (dest==0);
    }
};