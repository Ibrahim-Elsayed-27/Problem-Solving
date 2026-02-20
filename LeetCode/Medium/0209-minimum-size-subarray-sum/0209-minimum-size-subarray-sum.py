class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        start_ptr = 0
        end_ptr = 0
        sum_sub = 0
        min_len = len(nums) + 1
        while(end_ptr < len(nums)):
            sum_sub += nums[end_ptr]
            while(sum_sub >= target ):
                min_len = min(min_len, end_ptr - start_ptr + 1)
                sum_sub -= nums[start_ptr]
                start_ptr += 1


            end_ptr += 1

        if(min_len > len(nums)):
            return 0
        return min_len