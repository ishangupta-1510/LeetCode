class Solution {
public:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j,int n,int m){
        int crow[] = {0,0,-1,1};
        int ccol[] = {-1,1,0,0};
        if(grid1[i][j] == 0){
            return false;
        }
        grid2[i][j] = 0;
        bool result = true;
        for(int k=0;k<4;k++){
            int nrow = i+crow[k];
            int ncol = j+ccol[k];
            if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and grid2[nrow][ncol] == 1){
                result &= dfs(grid1,grid2,nrow,ncol,n,m);
            }
        }
        return result;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size();
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j] == 1){
                    if(dfs(grid1,grid2,i,j,n,m)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
