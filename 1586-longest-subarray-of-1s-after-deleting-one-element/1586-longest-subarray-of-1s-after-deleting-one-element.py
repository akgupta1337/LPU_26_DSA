class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        max_len = l = zero_count = 0
        for r in range(0, len(nums)):
            if(nums[r] == 0):
                zero_count += 1
            while(zero_count > 1):
                if(nums[l] == 0):
                    zero_count -= 1
                l += 1
            max_len = max(max_len, r - l)
        return max_len
            

        