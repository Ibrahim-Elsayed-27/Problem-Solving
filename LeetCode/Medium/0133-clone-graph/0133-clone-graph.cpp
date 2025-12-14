/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        queue<Node*> bfs_queue;
        bfs_queue.push(node);

        unordered_map<Node*, Node*> clone;
        clone[node] = new Node(node->val);
        

        while (!bfs_queue.empty()) {
            Node* current = bfs_queue.front();
            bfs_queue.pop();
            for (Node* neighbour : current->neighbors) {
                if (clone.find(neighbour) == clone.end())  {
                    bfs_queue.push(neighbour); 
                    Node* new_node = new Node(neighbour->val);
                    clone[neighbour] = new_node;
                }
                    
                clone[current]->neighbors.push_back(clone[neighbour]);
                
                

            }
        }
        return clone[node];
    }
};