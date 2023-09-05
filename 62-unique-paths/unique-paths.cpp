class Solution {
public:
    int countpath(int m,int n,vector<vector<int>> &dp){
        
        if(m==0 and n==0){
            return 1;
        }
        else if(m<0 or n<0){
            return 0;
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        return dp[m][n] = countpath(m-1,n,dp)+countpath(m,n-1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return countpath(m-1,n-1,dp);
    }
};