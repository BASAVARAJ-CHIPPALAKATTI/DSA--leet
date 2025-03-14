//first think about broute force O(N)^2
// then binary search O(log(n))

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int maxOne=0;
        long long totalcandy=0;
        for(int i=0;i<candies.size();i++){
            maxOne=max(maxOne,candies[i]);
            totalcandy+= candies[i];
        }
        if(totalcandy < k){
            return 0;
        }

        // binary search b/w 1 to maxOne
        int l=1;
        int h=maxOne;
        int result=0;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(serveCandy(mid,candies,k)){
                result=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return result;
    }
    bool serveCandy(int mid, vector<int>&candies,long long k){
        for(int i=0;i<candies.size();i++){
            k-=candies[i]/mid;

            if(k <=0){
                return true;
            }
        }
        return false;
    }
};