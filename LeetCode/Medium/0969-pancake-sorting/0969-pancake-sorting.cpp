class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> flips;
        int n = arr.size();

        for (int currSize = n; currSize > 1; --currSize) {
            int maxIndex = 0;

            for (int i = 0; i < currSize; ++i) {
                if (arr[i] > arr[maxIndex]) {
                    maxIndex = i;
                }
            }

            if (maxIndex == currSize - 1) continue;

            if (maxIndex != 0) {
                flips.push_back(maxIndex + 1);
                reverse(arr.begin(), arr.begin() + maxIndex + 1);
            }

            flips.push_back(currSize);
            reverse(arr.begin(), arr.begin() + currSize);
        }

        return flips;
    }
};
