//easy and own
class Solution {
public:
    int countLargestGroup(int n) {
        int maxsize=0;
        unordered_map<int,int>mp;

        for(int i=1;i<=n;i++){
            int curr=i;
            int currans=0;
            while(curr>0){
                currans+=curr%10;
                curr=curr/10;
            }
            mp[currans]++;
            maxsize=max(maxsize,mp[currans]);
        }
        int no_maxsize=0;
        for(auto pair : mp){
            if(pair.second == maxsize){
                no_maxsize++;
            }
        }
        return no_maxsize;
    }
};