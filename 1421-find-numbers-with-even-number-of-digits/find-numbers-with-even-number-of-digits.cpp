class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int num : nums){
            string n= to_string(num);
            if(n.size()%2==0){
                count++;
            }
        }
        return count;
    }

};