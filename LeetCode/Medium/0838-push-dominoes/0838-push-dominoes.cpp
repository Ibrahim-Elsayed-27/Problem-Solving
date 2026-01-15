class Solution {
public:
    string pushDominoes(string s) {
        int n = s.size();
        vector<int> right(n, -1), left(n, -1);

        int lastR = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R') lastR = i;
            else if (s[i] == 'L') lastR = -1;
            right[i] = lastR;
        }

        int lastL = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == 'L') lastL = i;
            else if (s[i] == 'R') lastL = -1;
            left[i] = lastL;
        }

        for (int i = 0; i < n; ++i) {
            if (s[i] != '.') continue;

            int r = right[i];
            int l = left[i];

            if (r == -1 && l == -1) continue;
            if (r == -1) s[i] = 'L';
            else if (l == -1) s[i] = 'R';
            else {
                int dr = i - r;
                int dl = l - i;
                if (dr < dl) s[i] = 'R';
                else if (dl < dr) s[i] = 'L';
            }
        }

        return s;
    }
};
