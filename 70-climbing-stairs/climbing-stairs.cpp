class Solution {
public:
    int climbStairs(int n,vector<int>& dp){
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = climbStairs(n-1,dp)+climbStairs(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(max(n+1,3),-1);
        dp[1] = 1,dp[2] = 2;
        climbStairs(n,dp);
        for(int i=0;i<n+1;i++){
            cout<<dp[i]<<' ';
        }
        return dp[n];
    }
};