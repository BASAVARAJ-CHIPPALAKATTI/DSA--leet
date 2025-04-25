class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater=0;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            //min size * dist
            int minh=min(height[i],height[j]);
            int currwater=minh*(j-i);
            maxwater=max(maxwater,currwater);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxwater;
    }
};