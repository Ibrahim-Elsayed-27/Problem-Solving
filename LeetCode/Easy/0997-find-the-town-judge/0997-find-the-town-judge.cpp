class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() < 1){
            if(n == 1) return n;
            return -1;
        }
        vector<int> degrees(n, 0);

        for(const auto& relation: trust){
            degrees[relation[1]-1]++;
            degrees[relation[0]-1]--;
        }

        for(int i =0 ; i<degrees.size(); ++i){
            if(degrees[i] == n-1) return i+1;
        }
        

        return -1;
    }
};