class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int count=0;
        int i=0;
        int j=0;
        unordered_map<int,int>mp;
        while(j<fruits.size()){
            mp[fruits[j]]++;
            if(mp.size()<=2){
                count=max(count,j-i+1);
            }
            else{
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0){
                    mp.erase(fruits[i]);
                }
                i++;
            }
            j++;
        }
        return count;
    }
};