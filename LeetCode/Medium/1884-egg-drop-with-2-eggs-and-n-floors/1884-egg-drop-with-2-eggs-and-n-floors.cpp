class Solution {
public:
    int twoEggDrop(int n) {
        float i = 0;
        double  k = 0;
        while(k < n){
            ++i;
            k = i * ((i+1)/2.0);   
        }
        return i;
    }
};