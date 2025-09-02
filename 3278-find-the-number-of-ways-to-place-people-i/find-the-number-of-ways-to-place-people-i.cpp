class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int res=0;
        int n=points.size();
        for(int i=0;i<n;i++){
            //upper bound
            int x1=points[i][0];
            int y1=points[i][1];

            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                int x2=points[j][0];
                int y2=points[j][1];
                //lower bound
                if(x1<=x2 && y1>=y2){
                    //in between these reactangle point check
                    bool point_in_rect=false;
                    for(int k=0;k<n;k++){
                        if(k==j || i==k){
                            continue;
                        }
                        int x3=points[k][0];
                        int y3=points[k][1];
                        if(x1 <=x3 && y1 >=y3 && x2>=x3 && y2<=y3){
                            point_in_rect=true;
                            break;
                        }
                    }
                    if(!point_in_rect){
                        res++;
                    }
                }
            }
        }
        return res;
    }
};