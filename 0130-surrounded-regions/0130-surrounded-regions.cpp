class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n+1,vector<int> (m+1,0));
        for(int i=0;i<n;i++){
            if(board[i][0] == 'O'){
                dfs(board,vis,i,0,n,m);
            }
            if(board[i][m-1] == 'O'){
                dfs(board,vis,i,m-1,n,m);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i] == 'O'){
                dfs(board,vis,0,i,n,m);
            }
            if(board[n-1][i] == 'O'){
                dfs(board,vis,n-1,i,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board,vector<vector<int>>& vis,int i,int j,int n,int m){
        int crow[] = {0,0,-1,1};
        int ccol[] = {-1,1,0,0};
        vis[i][j] = 1;
        for(int k=0;k<4;k++){
            int nrow = i+crow[k];
            int ncol = j+ccol[k];
            if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and board[nrow][ncol] == 'O' && !vis[nrow][ncol]){
                dfs(board,vis,nrow,ncol,n,m);
            }
        }
    }
};