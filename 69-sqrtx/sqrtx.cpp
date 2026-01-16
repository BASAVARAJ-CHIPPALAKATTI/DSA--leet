class Solution {
public:
    int mySqrt(int x) {
        long long low=0;
        long long high=x;
        long long ans=0;
        while(low <= high){
            long long mid =low+ (high - low)/2;
    
            if(mid * mid >=x){
                ans =mid;
                high =mid-1;
            }
            else{
                low =mid+1;
            }
        }
        return (ans*ans==x) ? ans : ans-1;
    }
};