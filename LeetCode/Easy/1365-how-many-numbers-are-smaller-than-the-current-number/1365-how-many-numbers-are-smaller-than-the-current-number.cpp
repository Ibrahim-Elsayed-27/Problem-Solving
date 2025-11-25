class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> freq_arr(101, 0);
        for(int num: nums){
            freq_arr[num]+=1;
        }
        int sum_freq = 0;
        int old_sum_freq = 0;
        for(int i=0; i<101; ++i){
            old_sum_freq = sum_freq;
            sum_freq += freq_arr[i];
            freq_arr[i] = old_sum_freq;
        }

        vector<int> result;
        for(int num: nums){
            result.push_back(freq_arr[num]);
        }

        return result;
    }
};