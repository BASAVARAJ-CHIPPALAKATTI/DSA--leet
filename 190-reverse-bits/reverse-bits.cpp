class Solution {
public:
    int reverseBits(int n) {
        vector<int>bit(32,0);
        int i=31;
        while(n){
            bit[i--]=n&1;
            n >>=1;
        }
        int ans=0;
        for(int i=0;i<32;i++){
            ans |=(bit[i]<<i);
        }
        return ans;
    }
};