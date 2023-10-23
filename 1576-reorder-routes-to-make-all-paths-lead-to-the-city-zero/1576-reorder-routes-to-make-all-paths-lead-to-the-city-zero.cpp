class Solution {
public:
    // read votrubac and this
    //https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/discuss/661710/Simple-Explanation-or-DFS-with-edge-deletion-or-Idea-or-Code-or-Comments-or-Q-and-A
    unordered_map<int, unordered_set<int>> out, in;
    int ans = 0;
    unordered_map<int,int> vis;
    void dfs(int node) {
        
        vis[node]=1;
        for (int x: out[node]) {
            if(vis[x])
                continue;
            ans++; 
            dfs(x);
        }
        for (int x:in[node]) {
			if(vis[x])
                continue;
			// recurse.
            dfs(x);
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        ans = 0;
		// make graph.
        for (auto x: connections) {
            out[x[0]].insert(x[1]);
            in[x[1]].insert(x[0]);
        }
		// start with node 0.
        dfs(0);
        return ans;
    }
};