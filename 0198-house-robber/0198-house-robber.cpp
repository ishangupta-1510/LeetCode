class Solution {
public:
    int rec(int n, vector<int>& v,vector<int> &dp) {
        if (n <= 0) {
            return v[n];
        }
        if (n == 1) {
            return max(v[0], v[1]);
        }
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = max(rec(n - 1, v,dp), rec(n - 2, v, dp) + v[n]);
    }
    
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<int> dp(nums.size()+1,-1);
        return rec(nums.size() - 1, nums,dp);
    }
};