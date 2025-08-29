//explanation take from description

//possibility
// alice win when odd comes
// n of odd * m of even
// m of odd * n of even
// because odd+even=odd
//or even+odd=odd
class Solution {
public:
    long long flowerGame(int n, int m) {
        return (1LL*((n+1)/2) *(m/2)) +(1LL*((m+1)/2)*(n/2));
    }
};