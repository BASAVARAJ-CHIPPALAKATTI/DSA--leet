class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            if(digits[i]< 9){
                digits[i]++;
                return digits;
            }
            else{ // it may 9
               digits[i]=0;
            }
        }
        // if every number 9
        digits.insert(digits.begin(),1);
        return digits;
    }
};