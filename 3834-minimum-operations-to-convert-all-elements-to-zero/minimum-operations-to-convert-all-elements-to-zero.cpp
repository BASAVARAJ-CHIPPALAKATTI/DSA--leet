//think (own) brute force and than monotonic stack
class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int>st;
        int op=0;
        for( int i=0;i<nums.size();i++){
            
            while(!st.empty() && st.top() > nums[i]){ //we need break for lar elts
                st.pop();
            }
            if(nums[i]==0){  // we need to do break for all elts in stack
                continue;
            }
            if(st.empty() || st.top() < nums[i]){
                op++;
                st.push(nums[i]);
            }
            //if equal is that no need of push and operation
        }
        return op;
    }
};