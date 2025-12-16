class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int nodes = graph.size();
        //vector<vector<int>> adj_list(nodes, vector<int>{});
        vector<bool> visited(nodes, false);
        vector<bool> safe(nodes, false);
/*
        for(int i = 0; i<nodes; ++i){
            adj_list[i] = graph[i];
        }
        */
        vector<int> result;
        for(int i=0; i< nodes; ++i){
            if(!safe[i] && !dfs(i, graph, visited, safe)){
                ;
            }else{
                result.push_back(i);
            }

        }

        return result;
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