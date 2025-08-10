class Solution {
public:
    //sort the  n
    // sort all power of 2
    // compare it
    bool reorderedPowerOf2(int n) {
        string num= sorted_num(n);
        for(int i=0;i<=29;i++){
            if(num==sorted_num(1<<i)){
                return true;
            }
        }
        return false;
    }
    string sorted_num(int n){
        string num=to_string(n);
        sort(num.begin(),num.end());
        return num;
    }
};