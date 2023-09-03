class Solution {
public:
    int costt(vector<int>& cost,int n,vector<int>& dp){
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }
        dp[0] = cost[0];
        dp[1] = cost[1];
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = min(costt(cost,n-1,dp),costt(cost,n-2,dp)) + cost[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        return min(costt(cost,cost.size()-1,dp),costt(cost,cost.size()-2,dp));
    }
};