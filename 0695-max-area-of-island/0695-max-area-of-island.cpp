class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m,int& count){
        int drow[] = {0,0,-1,1};
        int dcol[] = {-1,1,0,0};
        grid[i][j] = 0;
        for(int k=0;k<4;k++){
            int newRow = i + drow[k];
            int newCol = j + dcol[k];
            if(newRow >= 0 and newRow < n and newCol>=0 and newCol < m and grid[newRow][newCol] == 1){
                count++;
                dfs(grid,newRow,newCol,n,m,count);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),mxcount=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    int count = 1;
                    dfs(grid,i,j,n,m,count);
                    mxcount = max(count,mxcount);
                }
            }
        }
        return mxcount;
    }
};