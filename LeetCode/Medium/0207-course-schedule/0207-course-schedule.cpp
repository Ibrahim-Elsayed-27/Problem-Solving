class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list(numCourses, vector<int>{});
        vector<bool> visited(numCourses, false);
        vector<bool> safe(numCourses, false);

        for(const vector<int>& edge: prerequisites){
            adj_list[edge[1]].push_back(edge[0]);
        }
        for(int i=0; i< numCourses; ++i){
            if(!safe[i] && !dfs(i, adj_list, visited, safe)){
                return false;
            }
        }

        return true;

    }

    bool dfs(int root, vector<vector<int>>& adj_list, vector<bool>& visited, vector<bool>& safe ){
        if(visited[root]){
            return false;
        }
        visited[root] = true;
        for(int neighbour: adj_list[root]){
            if(!safe[neighbour] && !dfs(neighbour, adj_list, visited, safe)) return false;
        }
        visited[root] = false;
        safe[root] = true;
        return true;

    }
};