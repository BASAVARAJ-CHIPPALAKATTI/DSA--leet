class Solution {
    public String longestPalindrome(String s) {
        int resLen = 0;
        String res = "";
        int n= s.length();
        for(int i = 0;i<n;i++){
            int low = i;
            int high = i;

            while(low >= 0 && high<n && (s.charAt(low) == s.charAt(high))){
                if(resLen < high - low +1 ){
                    res = s.substring(low,high+1);
                    resLen = Math.max(resLen,high - low +1);
                }
                low--;
                high++;
            }
            low = i;
            high = i+1;

            while(low >= 0 && high<n && (s.charAt(low) == s.charAt(high))){
                if(resLen < high - low +1 ){
                    res = s.substring(low,high+1);
                    resLen = Math.max(resLen,high - low +1);
                }
                low--;
                high++;
            }
        }
        return res;
    }
}