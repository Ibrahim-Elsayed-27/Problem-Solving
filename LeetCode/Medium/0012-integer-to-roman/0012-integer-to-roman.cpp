class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> mp = {
            {1, "I"}, {5, "V"},
            {10, "X"}, {50, "L"},
            {100, "C"}, {500, "D"},
            {1000, "M"}
        };

        string result = "";
        int unit = 1;

        while (num > 0) {
            int digit = num % 10;
            string part = "";

            if (digit == 4) {
                part = mp[unit] + mp[5 * unit];
            }
            else if (digit == 9) {
                part = mp[unit] + mp[10 * unit];
            }
            else {
                if (digit >= 5) {
                    part += mp[5 * unit];
                    digit -= 5;
                }
                while (digit--) {
                    part += mp[unit];
                }
            }

            result = part + result;

            num /= 10;
            unit *= 10;
        }

        return result;
    }
};
