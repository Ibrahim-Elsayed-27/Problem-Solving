class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        triplets = set()
        nums.sort()
        #print(nums)
        dict_nums = {val: i for i, val in enumerate(nums)}
        for i in range(len(nums) - 2):
            if(i>0 and nums[i] == nums[i-1]):
                continue
            for j in range(i+1, len(nums)):
                temp = -nums[i] - nums[j]
                temp_index = dict_nums.get(temp)
                if temp_index != None:
                    if(temp_index > j):
                        triple = tuple((nums[i], nums[j], temp))
                        triplets.add(triple)

        return [list(t) for t in triplets]