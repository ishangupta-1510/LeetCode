class Solution {
public:
    void dfs(Node* copy, Node* node, unordered_map<Node*, Node*>& m) {
        for (auto x : node->neighbors) {
            if (m.find(x) == m.end()) {
                Node* ncopy = new Node(x->val);
                copy->neighbors.push_back(ncopy);
                m[x] = ncopy;
                dfs(ncopy, x, m); // Recursively call dfs for the neighbor
            } else {
                copy->neighbors.push_back(m[x]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        if (node == NULL) {
            return NULL;
        }
        Node* copy = new Node(node->val);
        m[node] = copy;
        dfs(copy, node, m);
        return copy;
    }
};
