class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() < 1){
            if(n == 1) return n;
            return -1;
        }
        unordered_map<int, vector<int>> trusts;
        for(const auto& trust_relation: trust){
            trusts[trust_relation[0]].push_back(trust_relation[1]);
            if(trusts.find(trust_relation[1]) == trusts.end())
            trusts[trust_relation[1]].push_back(-1); 
        }
        for (const auto& entry : trusts) {
            if (entry.second[entry.second.size()-1] == -1) {
                for (const auto& entry2 : trusts){
                    if(entry2 != entry){
                        if(find(entry2.second.begin(), entry2.second.end(), entry.first) == entry2.second.end())
                        return -1;
                    } 
                } 
                return entry.first;  
            }
        }

        return -1;
    }
};