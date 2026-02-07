class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        numbers_index_dict = {}
        for i in range(len(numbers)):

            rest = target - numbers[i]
            if( rest in numbers_index_dict):
                return [numbers_index_dict[rest],i+1]
            else:
                numbers_index_dict[numbers[i]] = i+1
        
        #print(numbers_index_dict)
        return -1

        