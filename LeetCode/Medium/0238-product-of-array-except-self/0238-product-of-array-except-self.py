class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        left_mult = []
        mult = 1
        for num in nums:
            left_mult.append(mult)
            mult *= num

        right_mult = [0] * len(nums)
        mult = 1
        for i in range(len(nums)-1, -1, -1):
            right_mult[i] = mult
            mult *= nums[i]

        for i in range(len(nums)):
            nums[i] = left_mult[i] * right_mult[i]

        return nums

        