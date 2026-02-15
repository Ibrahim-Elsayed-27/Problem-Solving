class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;

        int i = a.size() - 1;
        int j = b.size() - 1;

        string result;

        while (i >= 0 || j >= 0) {
            char a_num = (i >= 0) ? a[i] : '0';
            char b_num = (j >= 0) ? b[j] : '0';

            int sum = (a_num - '0') + (b_num - '0') + carry;

            if(sum == 0) {
                result.push_back('0');
                carry = 0;
            }
            else if(sum == 1) {
                result.push_back('1');
                carry = 0;
            }
            else if(sum == 2) {
                result.push_back('0');
                carry = 1;
            }
            else if(sum == 3) {
                result.push_back('1');
                carry = 1;
            }

            i--;
            j--;
        }

        if(carry == 1) {
            result.push_back('1');
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
