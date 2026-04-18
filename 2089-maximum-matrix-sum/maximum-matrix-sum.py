class Solution(object):
    def maxMatrixSum(self, matrix):
        ans=0
        total_min=0
        minval=('inf')
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] < 0:
                    total_min+=1
                val=abs(matrix[i][j])
                ans+=val
                minval=min(minval,val)
        if total_min %2==0:
            return ans
        return ans-(minval*2)