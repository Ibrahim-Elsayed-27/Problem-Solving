class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        int n = arr.size();
        
        for (int num : arr) {
            freq[num]++;
        }
        
        priority_queue<int> pq;
        for (auto& [num, count] : freq) {
            pq.push(count);
        }
        
        int removed = 0;
        int set_size = 0;
        int half = n / 2;
        
        while (removed < half) {
            removed += pq.top();
            pq.pop();
            set_size++;
        }
        
        return set_size;
    }
};