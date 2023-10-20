class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(fresh == 0){
            return 0;
        }
        if(q.empty()){
            return -1;
        }
        int minutes = -1;
        while(!q.empty()){
            int size = q.size();
            int crow[] = {0,0,-1,1};
            int ccol[] = {-1,1,0,0};
            for(int i=0;i<size;i++){
                auto [a,b] = q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int nrow = a + crow[j];
                    int ncol = b + ccol[j];
                    if(nrow >= 0 and ncol >= 0 and nrow < n and ncol < m and grid[nrow][ncol] == 1){
                        grid[nrow][ncol] = 2;
                        fresh--;
                        q.push({nrow,ncol});
                    }
                }
            }
            minutes++;
        }
        return fresh == 0 ? minutes:-1;
    }
};