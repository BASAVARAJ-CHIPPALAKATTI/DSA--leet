class Solution:
    def hasSameDigits(self, s: str) -> bool:
        n = len(s)
        digits=[int(char) for char in s]
        while( n >2):
            for i in range (0,n-1):
                digits[i]=(digits[i]+digits[i+1])%10
            n-=1
        return digits[0]==digits[1]