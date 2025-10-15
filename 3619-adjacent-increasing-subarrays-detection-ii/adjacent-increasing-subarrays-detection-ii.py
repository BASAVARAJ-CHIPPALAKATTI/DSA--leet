class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        n=len(nums)
        ans=0
        prevSeq=0
        currSeq=1
        for i in range(1,n):
            if nums[i-1] < nums[i]:
                currSeq+=1
            else :
                prevSeq=currSeq
                currSeq=1
            ans=max(ans,int(currSeq/2))
            ans=max(ans,min(prevSeq,currSeq)) #we can make minimum these much k subarray here
        return ans
