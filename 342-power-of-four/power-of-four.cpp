class Solution {
public:
    bool isPowerOfFour(int n) {
        if( n <=0) return false;
        return( ((n & n-1)==0) &&(0b01010101010101010101010101010101) & n );
    }
    
};
// Approach:
// The binary representation of numbers with powers of four are the even powers of two
// i.e
// 1 = 00000001
// 4 = 00000100
// 16 = 00010000
// 64 = 01000000

// so the 1 arrives only at odd positions and there will only one 1 present in binary.