class Solution {
public:
    int countpath(int i,int j,int m,int n,vector<vector<int>>& dp){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i==m-1 and j==n-1){
            return 1;
        }
        else if(i>m-1 or j>n-1){
            return 0;
        }
        return dp[i][j] = countpath(i+1,j,m,n,dp)+countpath(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int result = countpath(0,0,m,n,dp);
        return result;
    }
};