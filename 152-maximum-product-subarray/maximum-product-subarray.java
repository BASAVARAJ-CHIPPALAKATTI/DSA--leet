class Solution {
    public int maxProduct(int[] nums) {
        int prod=  Integer.MIN_VALUE;
        int pref = 1;
        int suf = 1;
        int n = nums.length;
        for(int i = 0;i<n;i++){
            pref = pref * nums[i];
            prod = Math.max(pref,prod);
            if(pref == 0){
                pref = 1;
            }
            suf = suf * nums[n-i-1];
            prod = Math.max(suf,prod);
            if(suf == 0){
                suf = 1;
            }
        }
        return prod;
    }
}