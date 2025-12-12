class Solution {
private:
    unordered_map<int, vector<int>> tree;
    unordered_map<int, int> bob_visits_time;
    int bob_height;
    unordered_map<int, bool> visited;
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {

        for(const auto& edge: edges){
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        dfs_bob(0, bob, 0);
        for (auto& entry : bob_visits_time) {
            entry.second = bob_height - entry.second;
        //cout << "Node: " << entry.first << ", Time: " << entry.second << endl;
        }
        //cout<<bob_height;
        unordered_map<int,bool> alice_visited;
        return dfs_alice(0, 0, alice_visited, amount);
 
    }

    bool dfs_bob(int root,int target, int time){
        if(root == target){
            visited[root] = true;
            bob_height = time;
            bob_visits_time[root] = time;
            return true;
        }
        bool path_flag = false;
        visited[root] = true;
        for(int i = 0; i< tree[root].size(); ++i){
            if(visited.find(tree[root][i]) == visited.end()){
                path_flag = path_flag || dfs_bob(tree[root][i], target, time+1);
            }
        }
        if(path_flag){
            bob_visits_time[root] = time;
            return true;
        }

        return false;
    }


    int dfs_alice(int node, int time, unordered_map<int,bool>& visited, vector<int>& amount) {
        visited[node] = true;
        
        int profit = 0;
        if (bob_visits_time.find(node) == bob_visits_time.end()) {
            // Bob never visits → Alice gets full
            profit += amount[node];
        } else if (time < bob_visits_time[node]) {
            profit += amount[node];          // Alice arrives first
        } else if (time == bob_visits_time[node]) {
            profit += amount[node] / 2;      // Split with Bob
        }
        // else: Alice arrives after Bob → profit += 0

        int max_child_profit = INT_MIN;  // Track best path
        bool has_child = false;
        
        for (int child : tree[node]) {
            if (!visited[child]) {
                has_child = true;
                int child_profit = dfs_alice(child, time+1, visited, amount);
                max_child_profit = max(max_child_profit, child_profit);
            }
        }

        visited[node] = false;  // backtrack

        if (!has_child) return profit;  // leaf node
        else return profit + max_child_profit;  // best among all paths
    }

};