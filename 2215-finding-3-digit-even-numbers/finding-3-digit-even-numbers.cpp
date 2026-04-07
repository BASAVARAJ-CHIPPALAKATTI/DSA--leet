class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int digit: digits){
            mp[digit]++;
        }
        for(int i=100;i<999;i+=2){
            if(number_is_there(to_string(i),mp)){
                ans.push_back(i);
            }
        }
        return ans;
    }
    bool number_is_there(string num,unordered_map<int,int>mp){
        for(int i=0;i<=2;i++){
            if(!mp[num[i]-'0']){
                return false;
            }
            else{
                mp[num[i]-'0']--;
            }
        }
        return true;
    }

};