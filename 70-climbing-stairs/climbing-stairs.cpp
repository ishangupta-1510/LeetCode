class Solution {
public:
    int rec(int n,vector<int> &dp){
        if(n==1 or n==0){
            return 1;
        }
        if(dp[n]){
            return dp[n];
        }
        return dp[n] = rec(n-1,dp)+rec(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        return rec(n,dp);
    }
};