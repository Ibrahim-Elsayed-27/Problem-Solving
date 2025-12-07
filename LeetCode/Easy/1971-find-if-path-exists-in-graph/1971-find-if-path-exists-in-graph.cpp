class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(edges.size() < 1) return true;
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);  
        }

        vector<bool> visited(n, false);
        queue<int> bfs_queue;
        bfs_queue.push(source);
        while(!bfs_queue.empty()){
            int node = bfs_queue.front();
            bfs_queue.pop();
            if(node == destination) return true;
            for(int neighbor : graph[node]){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    bfs_queue.push(neighbor); 
                }
            }
        }

        return false;
    }
};