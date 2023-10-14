class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        if (n == 0 || m == 0) {
            return {};  // Return an empty result for empty input.
        }

        vector<vector<int>> visP(n, vector<int>(m, 0));
        vector<vector<int>> visA(n, vector<int>(m, 0));
        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            dfs(heights, 0, i, visP, n, m);
            dfs(heights, n - 1, i, visA, n, m);
        }
        for (int i = 0; i < n; i++) {
            dfs(heights, i, 0, visP, n, m);
            dfs(heights, i, m - 1, visA, n, m);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visP[i][j] && visA[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<int>>& vis, int n, int m) {
        int crow[] = {0, 0, -1, 1};
        int ccol[] = {-1, 1, 0, 0};
        vis[i][j] = 1;
        
        for (int k = 0; k < 4; k++) {
            int nrow = i + crow[k];
            int ncol = j + ccol[k];
            
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && heights[i][j] <= heights[nrow][ncol]) {
                dfs(heights, nrow, ncol, vis, n, m);
            }
        }
    }
};
