class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        start = 0
        answer = []
        for i in range(1,len(nums)):
            if(nums[i]-1 != nums[i-1]):
                if(i - 1 != start):
                    answer.append(f"{nums[start]}->{nums[i-1]}")
                else:
                    answer.append(f"{nums[i-1]}")

                start = i
                
                if(i == len(nums) -1):
                    answer.append(f"{nums[i]}")
            else:
                if(i == len(nums) -1):
                    answer.append(f"{nums[start]}->{nums[i]}")

        if(not answer):
            for num in nums:
                answer.append(f"{num}")
            


        return answer


        