class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0;
        int i=0;
        int j=height.size()-1;
        int currans=0;
        while(i<j){
            currans=(j-i)* min(height[i],height[j]);
            res=max(res,currans);

            if(height[i]< height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return res;
    }
};