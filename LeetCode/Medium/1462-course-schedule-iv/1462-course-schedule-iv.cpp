class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<vector<int>> adj_matrix(numCourses, vector<int>(numCourses,0));
        for(vector<int>& pre: prerequisites ){
            adj_matrix[pre[0]][pre[1]] = 1;
        }

        vector<vector<int>> connection = adj_matrix;
        for(int i=0; i< numCourses; ++i){
            queue<int> bfs_queue;
            vector<bool> visited(numCourses, false);
            bfs_queue.push(i);
            visited[i] = 1;
            while(!bfs_queue.empty()){
                int current = bfs_queue.front();
                bfs_queue.pop();
                connection[i][current] = 1;
                for(int j=0; j< numCourses; ++j){
                    if(adj_matrix[current][j] && !visited[j]){
                        bfs_queue.push(j);
                        visited[j] = 1;
                    }
                }
            }

        }
        vector<bool> results;
        for(vector<int>& query: queries){
            results.push_back(connection[query[0]][query[1]]);
        }

        return results;
        
    }
};