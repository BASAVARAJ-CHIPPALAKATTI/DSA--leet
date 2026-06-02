class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int>ans(queries.size(),0);
        sort(items.begin(),items.end());
        int maxval=items[0][1];
        for(int i=0;i<items.size();i++){
            maxval=max(maxval,items[i][1]);
            items[i][1]=maxval;
        }

        for(int i=0;i<queries.size();i++){
            int item=queries[i];
            int currans=0;
            int l=0;
            int h=items.size()-1;
            while(l<=h){
                int mid=l+(h-l)/2;
                if(items[mid][0] <= item){
                    currans=items[mid][1];
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }
            }
            ans[i]=currans;
        }
        return ans;
    }
};