class Solution {
public:
    vector<vector<int>>serve={{100,0},{75,25},{50,50},{25,75}};
    vector<vector<double>>t;
    double soupServings(int n) {
        if(n>=5000){
            return 1; //chances of completing A is more
        }
        t.resize(n+1,vector<double>(n+1,-0.1));
        return solve(n,n);
    }
    double solve(int A,int B){
        if(A <=0 && B<=0){
            return 0.5;
        }
        if(A <=0 ){
            return 1.0;
        }
        if(B <=0 ){
            return 0.0;
        }
        if(t[A][B]!= -0.1){
            return t[A][B];
        }
        double probability=0.0;
        for( auto x : serve){
            int a_serve=x[0];
            int b_serve=x[1];
            probability+= 0.25*solve(A-a_serve, B-b_serve);
        }
        return t[A][B]=probability;
    }
};