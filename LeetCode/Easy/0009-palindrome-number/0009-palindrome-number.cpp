class Solution {
public:
    bool isPalindrome(int x) {
        if(x< 0){
            return false;
        }
        long long x_reversed = 0;
        long long temp = x;

        while(temp>0){
            x_reversed *= 10;
            x_reversed += temp%10;
            temp = temp / 10;
        }
        
        return x == x_reversed;
    }
};