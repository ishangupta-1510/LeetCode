class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(),m=grid[0].size(),island = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    island++;
                    dfs(grid,i,j);
                }
            }
        }
        return island;
    }
    void dfs(vector<vector<char>>& grid,int i,int j){
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        for(int k=0;k<4;k++){
            dfs(grid,drow[k]+i,dcol[k]+j);
        }
    }
};