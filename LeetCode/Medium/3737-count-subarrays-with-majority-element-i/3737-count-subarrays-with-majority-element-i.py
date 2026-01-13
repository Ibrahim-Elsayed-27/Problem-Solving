class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:

        n = len(nums)
        pref = [1] if nums[0] == target else [0]

        for i in range(1,n):
            if nums[i] == target:
                pref.append(pref[i-1] + 1)
            else:
                pref.append(pref[i-1])
        ans = 0
        for i in range(n):
            for j in range(i+1):
                count_target = pref[i] - (pref[j-1] if j > 0 else 0)
                if count_target > (i - j + 1) // 2:
                    ans += 1
        return ans