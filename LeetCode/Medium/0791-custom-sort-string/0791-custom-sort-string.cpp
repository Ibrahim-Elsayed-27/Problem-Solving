class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> order_freq_priority(26, -1);
        int order_size =  order.size();
        for(int i=0; i< order_size; ++i){
            order_freq_priority[order[i] - 97] = order_size - i - 1;
        }
        priority_queue<pair<int, char>> s_max_heap;
        for(char ch: s){
            s_max_heap.push(make_pair(order_freq_priority[ch - 97], ch));
        }
        int i = 0;
        while(!s_max_heap.empty()){
            s[i] = s_max_heap.top().second;
            s_max_heap.pop();
            ++i;
        }



        return s;
    }
};