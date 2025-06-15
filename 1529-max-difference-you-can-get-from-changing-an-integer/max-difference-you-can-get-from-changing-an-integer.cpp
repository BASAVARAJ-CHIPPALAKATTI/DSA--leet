class Solution {
public:
    int maxDiff(int num) {
        string maxone = to_string(num);
        string minone = maxone;
        for(int i=0;i<maxone.size();i++){
            char ch=maxone[i];
            if(ch!='9'){
                replace(maxone.begin(),maxone.end(),ch,'9');
                break;
            }
        }
        for(int i=0;i<minone.size();i++){
            char ch=minone[i];
            if(i==0){
                if(ch!='1'){
                    replace(minone.begin(),minone.end(),ch,'1');
                    break;
                }
            }
            else{
                if(ch!='0' && ch!='1'){
                    replace(minone.begin(),minone.end(),ch,'0');
                    break;
                }
            }
        }
        return stoi(maxone) - stoi(minone);
    }
};