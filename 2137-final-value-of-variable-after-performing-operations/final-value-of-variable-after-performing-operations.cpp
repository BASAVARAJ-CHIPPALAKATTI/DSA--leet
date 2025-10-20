class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        for( string oper:operations){
            if(oper=="X++" || oper=="++X"){
                ans++;
            }
            else{
                ans--;
            }
        }
        return ans;
    }
};