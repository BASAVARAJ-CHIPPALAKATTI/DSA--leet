class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totalsum=n*(n+1)/2;
        int divisiblebym=m*(n/m)*((n/m)+1)/2;

        return totalsum-2*(divisiblebym);
    }
};