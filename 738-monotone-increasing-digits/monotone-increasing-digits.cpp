// traverse from right to left
// if prev grt make it num -1 and next num make it 9
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string num =to_string(n);
        int mark =num.size();
        for(int i=num.size()-1;i>0;i--){
            if(num[i] < num[i-1]){
                mark=i;
                num[i-1]=num[i-1]-1;
            }
        }
        for(int i=mark;i<num.size();i++){
            num[i]='9';
        }
        return stoi(num);
    }
};