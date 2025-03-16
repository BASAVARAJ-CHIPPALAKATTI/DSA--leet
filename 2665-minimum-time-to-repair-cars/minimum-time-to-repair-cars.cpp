// binary search on minuters from 1 to larger elt *cars*cars

class Solution {
public:
    typedef long long ll;
    long long repairCars(vector<int>& ranks, int cars) {
        ll l=1;
        int maxcar= *max_element(ranks.begin(),ranks.end());
        ll h=1ll* maxcar* cars*cars;
        ll result=-1;
        while(l<=h){
            ll mid=l+(h-l)/2;
            if(ispossible(ranks,cars,mid)){
                result=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
    bool ispossible(vector<int>&ranks,int cars,long long mid){
        //minutes(mid)= r(ranks[i]) * n^2
        //we need to count is possible in this minute we do car repair
        //n=sqrt(mid/r)
        ll count=0;
        for(int i=0;i<ranks.size();i++){
            count+=sqrt(mid/ranks[i]);
        }
        return (count>= cars);
    }
};