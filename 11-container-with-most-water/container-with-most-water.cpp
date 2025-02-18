class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water=0;
        int low=0;
        int high=height.size()-1;
        while(low<=high){
            int small=min(height[low],height[high]);
            int dist=(high-low);
            max_water=max(max_water,dist*small);
            if(height[low]<height[high]){
                low++;
            }
            else {
                high--;
            }
        }
        return max_water;
    }
};