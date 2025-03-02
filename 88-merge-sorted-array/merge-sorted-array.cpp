// use two pointer form last
// we need do until nums2 become empty means(traverse all elts)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int i=m-1;
       int j=n-1;
       int fromlast=m+n-1;
       while(j>=0){
          if(i>=0 && nums1[i]>=nums2[j]){
            nums1[fromlast--]=nums1[i--];
          }
          else{
            nums1[fromlast--]=nums2[j--];
          }
       }
    }
};