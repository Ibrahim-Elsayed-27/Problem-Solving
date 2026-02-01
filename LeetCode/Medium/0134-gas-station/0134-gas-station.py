class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        gas_diff_cost_prefix = [gas[0] - cost[0]]
        min_index = 0
        min_val = gas_diff_cost_prefix[min_index]
        sum_gas_diff_cost = min_val
        for i in range(1, len(gas)):
            diff = gas[i] - cost[i]
            sum_gas_diff_cost += diff 
            new_val = gas_diff_cost_prefix[i-1] + diff
            if (new_val < min_val):
                min_val  = new_val
                min_index = i
            gas_diff_cost_prefix.append(new_val)
        

        # check solution
        solution  = (min_index+1) % len(gas)
        if(sum_gas_diff_cost >= 0):
            return solution

        return -1
        