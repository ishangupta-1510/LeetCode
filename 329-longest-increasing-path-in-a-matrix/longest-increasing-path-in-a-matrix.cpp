class Solution {
public:
    int path(vector<vector<int>>& matrix,int i,int j,int n,int m,vector<vector<int>> &dp){
        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,-1,0,1};
        int ans = 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        for(int k=0;k<4;k++){
            if(drow[k]+i>=0 and dcol[k]+j>=0 and drow[k]+i<n and dcol[k]+j<m and matrix[drow[k]+i][dcol[k]+j] > matrix[i][j])
            ans = max(ans,1+path(matrix,i+drow[k],j+dcol[k],n,m,dp));
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        if (n == 0) return 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,path(matrix,i,j,n,m,dp));
            }
        }
        return ans+1;
    }
};