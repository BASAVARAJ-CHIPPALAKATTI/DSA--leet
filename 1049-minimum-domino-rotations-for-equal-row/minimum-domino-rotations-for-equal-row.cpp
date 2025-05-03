class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int topswap=0;
        int bottomswap=0;
        int j;
        for(int i=1;i<=6;i++){
            for( j=0;j<tops.size();j++){
                if(tops[j]==i && bottoms[j]==i){
                    continue;
                }
                else if(tops[j]==i || bottoms[j]==i){
                    if(tops[j]==i){
                        topswap++;
                    }
                    else{
                        bottomswap++;
                    }
                }
                else{
                    topswap=0;
                    bottomswap=0;
                    break;
                }
            }
            if(j==tops.size()){
                return min(topswap,bottomswap);
            }
        }
        return -1;
    }
};