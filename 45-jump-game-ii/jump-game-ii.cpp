// make the window of nums[i]
// again find lar in window 
// again make window
// during making window make jump++
class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0;
        int l=0,h=0;
        while(h<nums.size()-1){
            int farthest=0;
            for(int i=l;i<=h;i++){
                farthest=max(i+nums[i],farthest);
            }
            jump++;
            l=h+1;
            h=farthest;
        }
        return jump;
    }
};