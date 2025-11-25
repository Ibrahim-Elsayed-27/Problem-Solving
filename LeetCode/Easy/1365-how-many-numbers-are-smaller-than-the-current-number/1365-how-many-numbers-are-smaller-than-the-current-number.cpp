class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> copy = nums;
        vector<int> freq_arr(101, 0);
        sort(copy.begin(), copy.end());
        freq_arr[copy[0]] = 0;
        int unrepeated_counter = 0;
        for(int i = 1;i< copy.size();++i){
            if(copy[i] == copy[i-1]){
                freq_arr[copy[i]] = unrepeated_counter;                
            }
            else{
                freq_arr[copy[i]] = i;
                unrepeated_counter = i;

            }
        }
        for(int i = 0; i< nums.size();++i){
            nums[i] = freq_arr[nums[i]];
        }

        return nums;
    }
};