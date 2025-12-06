char* longestPalindrome(char* s) {
    int n=strlen(s);
    if(n==0){
        return "";
    }
        int st=0;
        int end=0;
        for(int i=0;i<n;i++){
            int low=i;
            int high=i;
            while(low >=0 && high <n && s[low]==s[high]){
                if(end-st+1 < high-low+1){
                    end=high;
                    st=low;
                }
                low--;
                high++;
            }

            low=i;
            high=i+1;
            while(((low >=0) && (high <n)) && (s[low]==s[high])){
                if(end-st+1 < high-low+1){
                    end=high;
                    st=low;
                }
                low--;
                high++;
            }
        }
        int len = end - st + 1;
        char* ans=(char*)malloc(len+1);
        strncpy(ans,s+st,len);
        ans[len] = '\0';
        return ans;
}