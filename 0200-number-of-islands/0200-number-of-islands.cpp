class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(grid,i,j,n,m);
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
        int drow[] = {0, 0, -1, 1};
        int dcol[] = {-1, 1, 0, 0};
        grid[i][j] = '0'; // Change the current cell to '0' to mark it as visited
        for (int k = 0; k < 4; k++) {
            int newRow = i + drow[k];
            int newCol = j + dcol[k];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == '1') {
                dfs(grid, newRow, newCol, n, m);
            }
        }
    }

};