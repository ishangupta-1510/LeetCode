class Solution {
public:
    int rec(int i,vector<int>& nums,int cur,vector<vector<int>>& dp){
        if(dp[cur+1][i]!=-1){
            return dp[cur+1][i];
        }
        if(i >= nums.size()){
            return 0;
        }
        int take = INT_MIN,nottake = INT_MIN;
        if(cur<0 || nums[i]>nums[cur]){
            take = 1 + rec(i+1,nums,i,dp);
        }
        nottake = rec(i+1,nums,cur,dp);
        return dp[cur+1][i] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        int k = rec(0,nums,-1,dp);
        return k;
    }
};