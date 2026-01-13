class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if (n < 3) return n;

        int start_window = 0;
        int max_fruits = 0;

        int two_fruits[2][2];
        two_fruits[0][0] = fruits[0]; two_fruits[0][1] = 0;
        int fruit_count = 1; 

        for (int end_window = 0; end_window < n; ++end_window) {
            int curr = fruits[end_window];

            bool found = false;
            for (int i = 0; i < fruit_count; ++i) {
                if (two_fruits[i][0] == curr) {
                    two_fruits[i][1] = end_window; 
                    found = true;
                    break;
                }
            }

            if (!found) {
                if (fruit_count < 2) {
                    two_fruits[fruit_count][0] = curr;
                    two_fruits[fruit_count][1] = end_window;
                    fruit_count++;
                } else {
                    int remove_idx = (two_fruits[0][1] < two_fruits[1][1]) ? 0 : 1;
                    int keep_idx = 1 - remove_idx;

                    start_window = two_fruits[remove_idx][1] + 1;

                    
                    two_fruits[remove_idx][0] = curr;
                    two_fruits[remove_idx][1] = end_window;
                }
            }

            
            max_fruits = max(max_fruits, end_window - start_window + 1);
        }

        return max_fruits;
    }
};
