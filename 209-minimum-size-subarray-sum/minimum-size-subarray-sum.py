class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        i=0
        j=0
        ans=(inf)
        sum=0
        while j < len(nums):
            sum+=nums[j]
            while sum >= target:
                ans=min(ans,j-i+1)
                sum-=nums[i]
                i+=1
                
            j+=1
        if ans==(inf):
            return 0
        return ans
