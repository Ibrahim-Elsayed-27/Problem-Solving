class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        k %= n

        end_part = nums[n - k:]
        first_part = nums[:n - k]

        nums[:] = end_part + first_part
