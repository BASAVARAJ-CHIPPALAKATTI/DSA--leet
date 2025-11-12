//
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int countone=0;

        int oper=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                countone++;
            }
        }
        if(countone>0){
            return n-countone;
        }
        for(int i=0;i<n-1;i++){
            int Gcd=nums[i];
            for(int j=i+1;j<n;j++){
                Gcd=gcd(Gcd,nums[j]);
                if(Gcd==1){
                    oper=min(oper,j-i);
                    break;
                }
            }
        }
        if(oper!=INT_MAX){
            return oper + n-1;
        }
        return -1;
       
    }
    int gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
};