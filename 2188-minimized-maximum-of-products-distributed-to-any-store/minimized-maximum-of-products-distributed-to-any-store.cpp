class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int ans=0;
        int low=1;
        int high=*max_element(quantities.begin(),quantities.end());

        while(low <= high){
            int mid=low+(high-low)/2;
            if(possible(n,quantities,mid)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    bool possible(int n,vector<int>& quantities,int val){
        for(int i=0;i<quantities.size();i++){
            n -=((quantities[i] + val-1)/val);
            if(n < 0){
                return false;
            }
        }
        return true;
    }
};