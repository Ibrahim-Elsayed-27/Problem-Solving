class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> max_heap;
        for(int num: nums){
            max_heap.push(num);
        }
        while(k > 1){
            max_heap.pop();
            --k;
        }

        return max_heap.top();
    }
};