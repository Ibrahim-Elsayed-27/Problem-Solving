class Solution:
    def isGood(self, nums: List[int]) -> bool:
        length = len(nums)
        if(length <= 2):
            return nums == [1, 1]
        good_sum = [0] * length 
        n_sum = [0] * length
        for i in range(length):
            if((nums[i] - 1) > length-1):
                return False
            good_sum[i] += 1
            n_sum[nums[i] - 1] += 1 

        good_sum = good_sum[:length-1]
        good_sum[-1] += 1
        n_sum = n_sum[:length-1]
        #print(good_sum)
        #print(good_sum, n_sum)
        return good_sum == n_sum
