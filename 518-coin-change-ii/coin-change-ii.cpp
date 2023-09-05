class Solution {
public:
    int coin(int amount,vector<int>& coins,int i,vector<vector<int>>& dp){
        if(i >= coins.size()){
            if(amount == 0){
                return 1;
            }
            return 0;
        }
        if(amount<0){
            return 0;
        }
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        return dp[i][amount] = coin(amount-coins[i],coins,i,dp)+coin(amount,coins,i+1,dp);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        return coin(amount,coins,0,dp);
    }
};