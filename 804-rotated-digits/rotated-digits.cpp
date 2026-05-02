class Solution {
public:
    int rotatedDigits(int n) {
        int i=1;
        int ans=0;
        while(i<=n){
            if(goodone(i)!=i){
                ans++;
            }
            i++;
        }
        return ans;
    }
    int goodone(int num){
        string n=to_string(num);
        string new_one;
        for(int i=0;i<n.size();i++){
            if(n[i]=='0'||n[i]=='1'||n[i]=='8'){
                new_one.push_back(n[i]);
            }
            else if(n[i]=='6' || n[i]=='9'){
               char c= (n[i]=='6') ? '9' : '6';
               new_one.push_back(c);
            }
            else if(n[i]=='2' || n[i]=='5'){
                char c= (n[i]=='2') ? '5' : '2';
                new_one.push_back(c);
            }
            else{
                return num;
            }
        }
        return stoi(new_one);
    }
};