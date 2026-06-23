class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>lmax(n);
        vector<int>rmax(n);
        for(int i=0;i<n;i++){
            if(i>0){
                lmax[i]=max(lmax[i-1],height[i]);
            }
            else{
                lmax[i]=height[i];
            }
        }
        for(int i=n-1;i>=0;i--){
            if(i < n-1){
                rmax[i]=max(rmax[i+1],height[i]);
            }
            else{
                rmax[i]=height[i];
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            res+=min(rmax[i],lmax[i])-height[i];
        }
        return res;
    }
};