class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> freq;
        for (char t : tasks){
            freq[t]++;
        }

        priority_queue<pair<int,char>> maxHeap;

        for (auto &p : freq){
            maxHeap.push({p.second, p.first});
        }

        queue<tuple<char,int,int>> cooldown;

        int time = 0;   
        while(!maxHeap.empty() || !cooldown.empty()){
            if(!cooldown.empty()){
                auto &[task, cnt, available] = cooldown.front();
                if (available < time){
                    maxHeap.push({cnt, task});
                    cooldown.pop();
                }
            }
            if(!maxHeap.empty()){
                auto [cnt, task] = maxHeap.top();
                maxHeap.pop();
                cnt--;
                if(cnt > 0){
                    cooldown.push({task, cnt, time + n});
                }
            }
            ++time;
        }

        return time;

        return 0;  
    }
};
