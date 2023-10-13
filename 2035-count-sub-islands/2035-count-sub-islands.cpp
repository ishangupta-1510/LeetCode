class Solution {
public:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int n, int m) {
        int crow[] = {0, 0, -1, 1};
        int ccol[] = {-1, 1, 0, 0};
        grid2[i][j] = 0;
        bool result = true; // Initialize the result as true.

        for (int k = 0; k < 4; k++) {
            int nrow = i + crow[k];
            int ncol = j + ccol[k];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid2[nrow][ncol] == 1) {
                result &= dfs(grid1, grid2, nrow, ncol, n, m);
            }
        }
        
        return result && grid1[i][j]; // Check both conditions: sub-island connected and the corresponding cell in grid1 is 1.
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size(), count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1 && dfs(grid1, grid2, i, j, n, m)) {
                    count++;
                }
            }
        }

        return count;
    }
};
