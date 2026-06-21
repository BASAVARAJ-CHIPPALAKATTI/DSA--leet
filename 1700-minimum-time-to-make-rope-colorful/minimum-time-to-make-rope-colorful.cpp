class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        int total=0;
        int maxval=0;
        int seq=1;
        for(int i=0;i<colors.size();i++){
            if(i>0 && colors[i-1]==colors[i]){
                seq++;
                maxval=max(maxval,neededTime[i]);
                total+=neededTime[i];
            }
            else{
                if(seq > 1){
                    ans+=(total-maxval);
                }
                seq=1;
                maxval=neededTime[i];
                total=neededTime[i];
            }
        }
        if(seq > 1){
            ans+=(total-maxval);
        }
        return ans;
    }
};