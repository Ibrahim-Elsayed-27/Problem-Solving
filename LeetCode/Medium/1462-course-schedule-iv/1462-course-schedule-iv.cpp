class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj_list;
        for(const auto& edge: prerequisites){
            adj_list[edge[0]].push_back(edge[1]);
        }
        vector<bool> result;
        for(const auto& query: queries){
            unordered_map<int, bool> visited;
            result.push_back(dfs(adj_list, query[0],query[1], visited));
        }


        return result;
    }

    bool dfs(unordered_map<int,vector<int>>& adj_list, int root, int target, unordered_map<int, bool>& visited){
        visited[root] = true;
        if(root == target){
            return true;
        }
        for(int i = 0; i< adj_list[root].size(); ++i){
            
            if(!visited[adj_list[root][i]] && dfs(adj_list, adj_list[root][i], target, visited) ){
                return true;
            }
            
        }

        return false;
    }
};