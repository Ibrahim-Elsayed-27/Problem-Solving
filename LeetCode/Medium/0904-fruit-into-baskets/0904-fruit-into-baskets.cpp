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

        for(int end_window = 1; end_window < n; ++end_window){

            bool found = false;

            for(int i=0; i< fruit_count; ++i){
                if(two_fruits[i][0] == fruits[end_window]){
                    found = true;
                    two_fruits[i][1] = end_window;
                }else{
                    if(fruit_count ==1){
                        two_fruits[1][0] = fruits[end_window];
                        two_fruits[1][1] = end_window;
                        found = true;
                        fruit_count++;
                    }
                }
            }

            if(!found){
                if(two_fruits[0][1] < two_fruits[1][1]){
                    start_window = two_fruits[0][1] + 1;
                    two_fruits[0][0] = fruits[end_window];
                }else{
                    start_window = two_fruits[1][1] + 1;
                    two_fruits[1][0] = fruits[end_window];                    
                }
            }

            max_fruits = max(max_fruits, end_window - start_window);
        }

        return max_fruits+1;
    }
};
