class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 2:
            return n

        count = 1
        k = 1  # nums[0] is always valid
        prev_val = nums[0]

        for i in range(1, n):
            if nums[i] == prev_val:
                count += 1
                if count <= 2:
                    k += 1
                else:
                    nums[i] = '-'
            else:
                prev_val = nums[i]
                count = 1
                k += 1


        i = 0
        j = 0
        while i < k and j < n:
            if nums[i] != '-':
                i += 1
                j = max(j, i)
            else:
                if j <= i:
                    j = i + 1
                while j < n and nums[j] == '-':
                    j += 1
                if j == n:
                    break
                nums[i] = nums[j]
                nums[j] = '-'
                i += 1
                j += 1

        return k
