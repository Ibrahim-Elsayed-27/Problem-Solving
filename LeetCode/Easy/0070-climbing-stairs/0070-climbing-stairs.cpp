class Solution {
public:
    unordered_map<int, int> dp_memory;
    Solution() {
        dp_memory[0] = 1; 
        dp_memory[1] = 1; 
        }
    int climbStairs(int n) {
        if(dp_memory.find(n) != dp_memory.end()){
            return dp_memory[n];
        }

        dp_memory[n] = climbStairs(n-1) + climbStairs(n-2);
        return dp_memory[n];
    }
};