class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> freq_arr(2*edges.size(), 0);
        for(const auto& edge: edges){
            freq_arr[edge[0]]++;
            freq_arr[edge[1]]++;
        }
        int max = 0;
        for(int i = 0 ;i <freq_arr.size(); ++i){
            if(freq_arr[i] > freq_arr[max]){
                max = i;
            }
        }
        return max;
    }
};