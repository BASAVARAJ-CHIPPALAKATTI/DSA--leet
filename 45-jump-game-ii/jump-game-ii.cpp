// make the window of nums[i]
// again find lar in window 
// again make window
// during making window make jump++
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans=0;
        int j=0,i=0;
      
        while(j < nums.size()-1){
            int maxjump=0;
            for(int k=i;k<=j;k++){
                maxjump=max(maxjump,nums[k]+k);
            }
            ans++;
            i=j+1;
            j=maxjump;
        }
        return ans;
    }
};