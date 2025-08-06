
//know about segment tree
//revision
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<int>segment_tree(4*n,-1);

        build(0,0,n-1,baskets,segment_tree);
        int notfit=0;
        for(int i=0;i<n;i++){
            if(!query_seg_tree(0,0,n-1,fruits[i],segment_tree)){
                notfit++;
            }
        }
        return notfit;
    }


    void build(int i,int l,int r,vector<int>&baskets,vector<int>&segment_tree){
        if(l==r){
            segment_tree[i]=baskets[l]; //or r
            return;
        }
        int mid=l+(r-l)/2;
        build(2*i+1,l,mid,baskets,segment_tree);
        build(2*i+2,mid+1,r,baskets,segment_tree);

        //update
        segment_tree[i]=max(segment_tree[2*i+1],segment_tree[2*i+2]);
    }

    bool query_seg_tree(int i ,int l, int r,int val,vector<int>&segment_tree){
        if(val > segment_tree[i]){
            return false;
        } //not in this basket

        if(l==r){
            segment_tree[i]=-1;
            return true;
        }
        int m=l+(r-l)/2;
        bool placed=false;
        if(segment_tree[2*i+1]>=val){  //left side
            placed=query_seg_tree(2*i+1,l,m,val,segment_tree);
        }
        else{
            placed=query_seg_tree(2*i+2,m+1,r,val,segment_tree);
        }

        segment_tree[i]=max(segment_tree[2*i+1],segment_tree[2*i+2]);

        return placed;
    }
};