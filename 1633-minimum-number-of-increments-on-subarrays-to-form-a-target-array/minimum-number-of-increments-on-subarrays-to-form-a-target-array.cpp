class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans=0;
        int prev=0;
        for(int curr : target){
            if(curr > prev){
                ans+=curr-prev;
            }
            prev=curr;
        }
        
        return ans;
    }
};