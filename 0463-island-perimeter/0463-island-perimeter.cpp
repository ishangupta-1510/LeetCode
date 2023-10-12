class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    if(i == 0 or grid[i-1][j] == 0){
                        res++;
                    }
                    if(j == 0 or grid[i][j-1] == 0){
                        res++;
                    }
                    if(i == n-1 or grid[i+1][j] == 0){
                        res++;
                    }
                    if(j == m-1 or grid[i][j+1] == 0){
                        res++;
                    }
                }
            }
        }
        return res;
    }
};