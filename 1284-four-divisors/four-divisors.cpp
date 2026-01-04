class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res=0;
        for(int num : nums){
            res+= has_4_divisors(num);
        }
        return res;
    }
    int has_4_divisors(int num){
        int divisiors=0;
        int sum=0;
        for(int i=1;i<=sqrt(num);i++){
            if(num % i==0){
                int othernum=num/i;

                if(othernum==i){
                    divisiors++;
                    sum+=i;
                }
                else{
                    divisiors+=2;
                    sum+=i;
                    sum+=othernum;
                }
            }
            if(divisiors > 4){
                return 0;
            }
        }
        return (divisiors==4)? sum : 0;
    }
};