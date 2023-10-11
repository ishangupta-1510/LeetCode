class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1,INT_MAX);
        sort(coins.begin(),coins.end());
        dp[0] = 0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=amount;j++){
                if(j-coins[i] >= 0 and dp[j-coins[i]]!=INT_MAX){
                    dp[j] = min(1 + dp[j-coins[i]],dp[j]);
                }
            }
        }
        if(amount > 0 and dp[amount] == INT_MAX){
            return -1;
        }
        return dp[amount];
    }
};