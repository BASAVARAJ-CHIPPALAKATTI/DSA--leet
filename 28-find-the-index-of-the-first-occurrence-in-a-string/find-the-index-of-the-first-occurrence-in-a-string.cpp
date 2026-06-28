class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size()){
            return -1;
        }
        for(int i=0;i<=haystack.size()-needle.size();i++){
            int j=0;
            int k=i;
            if(haystack[i]==needle[j]){
                while(j<needle.size() && haystack[k]==needle[j]){
                    k++;
                    j++;
                }
                if(j==needle.size()){
                    return i;
                }
            }
        }
        return -1;
    }
};